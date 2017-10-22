//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

double polygonArea(const vdd &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        x1 = P[i].first, x2 = P[i + 1].first;
        y1 = P[i].second, y2 = P[i + 1].second;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

void pointsToLine(dd p1, dd p2, ddd &l) {
    double &a = l.first.first, &b = l.first.second, &c = l.second;
    double &x1 = p1.first, &y1 = p1.second, &x2 = p2.first;

    if (fabs(x1 - x2) < eps) // vertical line is fine
        a = 1.0, b = 0.0, c = -x1;

    else {
        a = -(y1 - p2.second) / (x1 - x2);
        b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        c = -(a * x1) - y1;
    }
}

// check coefficients a & b
bool areParallel(ddd l1, ddd l2) {
    return (fabs(l1.first.first - l2.first.first) < eps) &&
           (fabs(l1.first.second-l2.first.second) < eps);
}

// uses: areParallel -> lines
// returns true (+ intersection point) if two lines are intersect
bool areIntersect(ddd l1, ddd l2, dd &p) {
    double &a1 = l1.first.first, &b1 = l1.first.second, &c1 = l1.second;
    double &a2 = l2.first.first, &b2 = l2.first.second, &c2 = l2.second;
    double &x = p.first, &y = p.second;
    if (areParallel(l1, l2)) return false; // no intersection

    // solve system of 2 linear algebraic equations with 2 unknowns
    x = (b2 * c1 - b1 * c2) / (a2 * b1 - a1 * b2);

    // special case: test for vertical line to avoid division by zero
    y = -(fabs(b1) > eps ? a1 * x + c1 : a2 * x + c2);
    return true;
}

// line segment p-q intersect with line A-B.
dd lineIntersectSeg(dd p, dd q, dd A, dd B) {
    double px = p.first, py = p.second, qx = q.first, qy = q.second;
    double a = B.second - A.second, b = A.first - B.first;
    double c = B.first * A.second - A.first * B.second;
    double u = fabs(a * px + b * py + c);
    double v = fabs(a * qx + b * qy + c);
    return dd((px * v + qx * u) / (u + v), (py * v + qy * u) / (u + v));
}

//distance of points (Euclidean distance)
double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

// cross product
double cross(dd a, dd b) { return a.first * b.second - a.second * b.first; }

double cross(dd O, dd A, dd B) {
    return (A.first - O.first) * (B.second - O.second) -
           (A.second - O.second) * (B.first - O.first);
}

// converts 2 points to vector a->b
dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

// uses cross, toVec -> vectos AND lineIntersectSeg -> lines
// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
// to get the right cut just call the function with a, b reversed
vdd cutPolygon(dd a, dd b, const vdd &Q) {
    vdd P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size() - 1)
            left2 = cross(toVec(a, b), toVec(a, Q[i+1]));

        if (left1 > -eps) P.push_back(Q[i]); // Q[i] is on the left of ab
        if (left1 * left2 < -eps) // edge (Q[i], Q[i+1]) crosses line ab
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && P.back() != P.front())
        P.push_back(P.front()); // make P’s first point = P’s last point
    return P;
}

dd func(vdd p){
    vddd edges;
    int n = p.size() - 1;

    if(n == 3){
        double a = 0, b = 0;
        for (int i = 0; i < n; ++i)
            a += p[i].first, b += p[i].second;

        return dd(a / 3, b / 3);
    }


//    for (int i = 0; i < n; ++i) {
//        ddd l; pointsToLine(p[i], p[i+1], l);
//        edges.push_back(l);
//    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
//            ddd l;
//            pointsToLine(p[i], p[j], l);

            bool canDevide = true;

            for (int k = 0; k < n; ++k) {
                dd pp = lineIntersectSeg(p[k], p[k + 1], p[i], p[j]);
                if(fabs(dist(p[i], p[j]) - (dist(p[i], pp) + dist(p[j], pp)) <= eps) && pp != p[i] && p[j] != pp) {
                    canDevide = false;
                    break;
                }
            }
//            for(auto &ll : edges){
//                dd pp;
//                if(areIntersect(ll, l, pp) && fabs(dist(p[i], p[j]) - (dist(p[i], pp) + dist(p[j], pp)) <= eps) && pp != p[i] && p[j] != pp){
//                    canDevide = false;
//                    break;
//                }
//            }

            if(canDevide){
                vdd p1, p2;
                p1 = cutPolygon(p[i], p[j], p);
                p2 = cutPolygon(p[j], p[i], p);

                double s1 = polygonArea(p1), s2 = polygonArea(p2);
                dd a = func(p1), b = func(p2);

                double aa = (s1 * a.first + s2 * b.first) / (s1 + s2);
                double bb = (s1 * a.second + s2 * b.second) / (s1 + s2);

                return dd(aa, bb);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n){
        vdd p;
        for (int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b;
            p.push_back(dd(a, b));
        }

        p.push_back(p[0]);

        dd ans = func(p);
        cout << ans.first << ' ' << ans.second << endl;

    }

    return 0;
}

