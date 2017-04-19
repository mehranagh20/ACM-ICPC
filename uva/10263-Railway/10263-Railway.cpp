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

// uses: toVec, dot, norm_sq, translate, scale -> vectors AND dist -> points
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (by reference)
double distToLine(dd p, dd a, dd b, dd &c) {
    // formula: c = a + u * ab
    dd ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance between p and c
}

// uses: toVec, dot, norm_sq, translate, scale, distToLine -> vectors AND dist -> points
// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (by reference)
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
    dd p;
    while(cin >> p.first >> p.second) {
        int n; cin >> n;
        dd f, s, ans; cin >> f.first >> f.second;
        double cur_dis = inf;
        for(int i = 0 ; i < n; i++) {
            cin >> s.first >> s.second;
            dd cur_p;
            double dis = distToLineSegment(p, f, s, cur_p);
            // cout << cur_p.first << " " << cur_p.second << endl;
            if(dis < cur_dis) {
                cur_dis = dis;
                ans = cur_p;
            }
            f = s;
        }
        cout << fixed << setprecision(4) << ans.first << endl << ans.second << endl;

    }


    return 0;
}
