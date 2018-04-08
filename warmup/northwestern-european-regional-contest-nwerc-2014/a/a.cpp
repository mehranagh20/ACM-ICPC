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
#define pi acos(-1)

double degToRad(double theta){ return theta * pi / 180.0; }
double radToDeg(double theta){ return theta * 180.0 / pi; }

//distance of points (Euclidean distance)
double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

// converts 2 points to vector a->b
dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

// nonnegative s = [<1 (shorter).. 1 (same).. >1 (longer)]
dd scale(dd v, double s) { return dd(v.first * s, v.second * s); }

// translate(move) p according to v
dd translate(dd p, dd v) { return dd(p.first + v.first , p.second + v.second); }

// dot product
double dot(dd a, dd b) { return (a.first * b.first + a.second * b.second); }

// norm of vector
double norm_sq(dd v) { return v.first * v.first + v.second * v.second; }

// uses toVec, norm_sq -> vectors AND radToDeg -> points
// NOTE!: returns angle aob in DEG
double angle(dd a, dd o, dd b) {
    dd oa = toVec(o, a), ob = toVec(o, b);
    double ans =  acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
    return radToDeg(ans);
}

// cross product
double cross(dd a, dd b) { return a.first * b.second - a.second * b.first; }

double cross(dd O, dd A, dd B) {
    return (A.first - O.first) * (B.second - O.second) -
           (A.second - O.second) * (B.first - O.first);
}

// uses: cross, toVec -> vectors
// returns true if point r is on the left side of line pq
// The left turn test is more famously known as the CCW (Counter Clockwise) Test.
bool ccw(dd p, dd q, dd r) { return cross(toVec(p, q), toVec(p, r)) > eps; }


// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double polygonPerimeter(const vdd &P) {
    double result = 0.0;
    for (int i = 0; i < P.size() - 1; ++i) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i + 1]);
    return result;
}

bool inPolygon(dd pt, const vdd &P) {
    if ((int)P.size() == 0) return false;

    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i + 1])) // left turn/ccw
            sum += degToRad(angle(P[i], pt, P[i + 1]));
        else // right turn/cw
            sum -= degToRad(angle(P[i], pt, P[i + 1]));
    }
    return fabs(fabs(sum) - 2 * pi) < eps;
}

// CONVEX HALL
// uses: cross -> vectors
// IMPORTANT!: the first point does not have to be replicated as the last point
vdd convexHull(vdd P){
    int n = P.size(),k = 0; vdd H(2*n);
    sort(P.begin(), P.end());
    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(H[k - 2], H[k - 1] , P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--){
        while(k >= t && cross(H[k - 2], H[k - 1] , P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k); return H;
}


// check coefficients a & b
bool areParallel(ddd l1, ddd l2) {
    return (fabs(l1.first.first - l2.first.first) < eps) &&
           (fabs(l1.first.second-l2.first.second) < eps);
}

// the answer is stored in the third parameter (pass by reference)
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

// uses: areParallel -> lines
// also check coefficient c. NOTE: uses areParallel!!
bool areSame(ddd l1, ddd l2) {
    return areParallel(l1 ,l2) && (fabs(l1.second - l2.second) < eps);
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


int main() {
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n){
        vdd inner(n, dd());
        for(auto &e: inner) cin >> e.first >> e.second;

        cin >> m; vdd outer(m, dd());
        for(auto &e: outer) cin >> e.first >> e.second;
        outer.push_back(outer[0]);

        vdd ans = convexHull(inner);
//        ans.push_back(ans[0]);
        inner.push_back(inner[0]);

        for (int i = 1; i <= m; ++i) {
            dd y = outer[i-1], x = outer[i];

            ddd l1;
            pointsToLine(x, y, l1);

            if(inPolygon(x, ans)){
                for (int j = 1; j <= ans.size(); ++j) {
                    dd a = ans[j-1], b = ans[j];
                    ddd l2;
                    pointsToLine(a, b, l2);

                    dd p;
                    if(areIntersect(l1, l2, p)){
                        if(fabs(dist(a, b) - (dist(a, p) + dist(p, b))) < eps) {
                            ans.insert(ans.begin() + j, x);
                            break;
                        }
                    }
                }
            }
        }

        cout << fixed << setprecision(10) << polygonPerimeter(ans) << endl;
    }


    return 0;
}
