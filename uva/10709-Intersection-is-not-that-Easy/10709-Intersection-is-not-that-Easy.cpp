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

double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

// nonnegative s = [<1 (shorter).. 1 (same).. >1 (longer)]
dd scale(dd v, double s) { return dd(v.first * s, v.second * s); }

// translate(move) p according to v
dd translate(dd p, dd v) { return dd(p.first + v.first , p.second + v.second); }

// dot product
double dot(dd a, dd b) { return (a.first * b.first + a.second * b.second); }

// norm of vector
double norm_sq(dd v) { return v.first * v.first + v.second * v.second; }

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

bool areParallel(ddd l1, ddd l2) {
    return (fabs(l1.first.first - l2.first.first) < eps) &&
    (fabs(l1.first.second-l2.first.second) < eps);
}

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

double distToLine(dd p, dd a, dd b, dd &c) {
    // formula: c = a + u * ab
    dd ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance between p and c
}

double distToLineSegment(dd p, dd a, dd b, dd &c) {
    dd ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { // closer to a
        c = dd(a.first, a.second);
        return dist(p, a); // Euclidean distance between p and a
    }
    if (u > 1.0){ // closer to b
        c = dd(b.first, b.second);
        return dist(p, b); // Euclidean distance between p and b
    }
    return distToLine(p, a, b, c); // run distToLine as above
}

int main() {
    ios::sync_with_stdio(0);
    dd a, b, c, d, tmp;
    string str1, str2;
    while(1) {
        cin >> a.first >> a.second >> b.first >> b.second >> str1 >> c.first >> c.second >> d.first >> d.second >> str2;
        if(str1 == "END" || str2 == "END") break;
        ddd line1, line2;
        pointsToLine(a, b, line1), pointsToLine(c, d, line2);
        if(str1 == "LS" && str2 == "L")
            swap(a, c), swap(b, d), swap(line1, line2), swap(str1, str2);
        double ans;
        if(str1 == "LS" && str2 == "LS") {
            if(areIntersect(line1, line2, tmp)) {
                double f = dist(a, tmp) + dist(b, tmp);
                double s = dist(c, tmp) + dist(d, tmp);
                if(f - dist(a, b) < eps && s - dist(c, d) < eps) ans = 0;
                else {
                    ans = distToLineSegment(a, c, d, tmp);
                    ans = min(ans, distToLineSegment(b, c, d, tmp));
                    ans = min(ans, distToLineSegment(c, a, b, tmp));
                    ans = min(ans, distToLineSegment(d, a, b, tmp));
                }
            }
            else {
                ans = distToLineSegment(a, c, d, tmp);
                ans = min(ans, distToLineSegment(b, c, d, tmp));
                ans = min(ans, distToLineSegment(c, a, b, tmp));
                ans = min(ans, distToLineSegment(d, a, b, tmp));
            }

        }
        else if(str1 == "L" && str2 == "LS") {
            if(areIntersect(line1, line2, tmp)) {
                double s = dist(c, tmp) + dist(d, tmp);
                if(s - dist(c, d) < eps) ans = 0;
                else
                    ans = min(distToLine(c, a, b, tmp), distToLine(d, a, b, tmp));
            }
            else
                ans = min(distToLine(c, a, b, tmp), distToLine(d, a, b, tmp));
        }

        else {
            if(areIntersect(line1, line2, tmp)) ans = 0;
            else ans = distToLine(a, c, d, tmp);
        }

        cout << fixed << setprecision(5) << ans << endl;
    }


    return 0;
}
