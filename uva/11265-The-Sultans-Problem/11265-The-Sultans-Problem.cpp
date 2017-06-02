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

dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

double cross(dd a, dd b) { return a.first * b.second - a.second * b.first; }

bool ccw(dd p, dd q, dd r) { return cross(toVec(p, q), toVec(p, r)) > eps; }

dd lineIntersectSeg(dd p, dd q, dd A, dd B) {
    double px = p.first, py = p.second, qx = q.first, qy = q.second;
    double a = B.second - A.second, b = A.first - B.first;
    double c = B.first * A.second - A.first * B.second;
    double u = fabs(a * px + b * py + c);
    double v = fabs(a * qx + b * qy + c);
    return dd((px * v + qx * u) / (u + v), (py * v + qy * u) / (u + v));
}

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

double polygonArea(const vdd &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        x1 = P[i].first, x2 = P[i + 1].first;
        y1 = P[i].second, y2 = P[i + 1].second;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

int main() {
    ios::sync_with_stdio(0);
    int n, w, h, x, y, tc = 0;
    while(cin >> n >> w >> h >> x >> y) {
        cout << "Case #" << ++tc << ": ";
        vdd convex = {{0, 0}, {0, h}, {w, h}, {w, 0}, {0, 0}};
        for(int i = 0; i < n; i++) {
            int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
            if(ccw(dd(x0, y0), dd(x1, y1), dd(x, y)))
                convex = cutPolygon(dd(x0, y0), dd(x1, y1), convex);
            else convex  = cutPolygon(dd(x1, y1), dd(x0, y0), convex);
        }
        cout << fixed << setprecision(3) << polygonArea(convex) << endl;
    }

    return 0;
}
