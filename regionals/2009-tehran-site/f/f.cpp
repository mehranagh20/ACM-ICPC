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

//distance of points (Euclidean distance)
double dist(dd p1, dd p2){
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
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

int n;
double d;
vii points;

vd memo;

double f(int id){
    if(id == n - 1) return 0;

    double &ans = memo[id];
    if(ans != -1) return ans;

    ans = inf;
    for (int i = id + 1; i < n; ++i) {

        bool b = true;
        for (int j = id + 1; j < i; ++j) {
            dd c;
            if((distToLine(points[j], points[id], points[i], c)) - d > eps){
                b = false;
                break;
            }
        }

        if(b)
            ans = min(ans, f(i) + dist(points[id], points[i]));
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    while(cin >> n && n){
        cin >> d;
        points.assign(n, ii());
        for(auto &e: points)
            cin >> e.first >> e.second;

        memo.assign(n + 10, -1);

        cout << fixed << setprecision(2) << f(0) << endl;
    }

    return 0;
}
