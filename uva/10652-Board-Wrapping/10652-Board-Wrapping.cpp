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
double pi = acos(-1.);

double degToRad(double theta){ return theta * pi / 180.0; }

dd rotate(dd p, dd loc, double theta) {
    p.first -= loc.first, p.second -= loc.second;
    double rad = degToRad(theta);
    return dd(p.first * cos(rad) - p.second * sin(rad) + loc.first,
              p.first * sin(rad) + p.second * cos(rad) + loc.second);
}

double cross(dd O, dd A, dd B) {
    return (A.first - O.first) * (B.second - O.second) -
            (A.second - O.second) * (B.first - O.first);
}

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
    int tc; cin >> tc;
    while(tc--) {
        vdd points;
        double total = 0, tri = 0;
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            double x, y, w, h, theta; cin >> x >> y >> w >> h >> theta;
            double h2 = h / 2, w2 = w / 2;
            points.push_back(rotate(dd(x + w2, y + h2), dd(x, y), 360 - theta));
            points.push_back(rotate(dd(x - w2, y + h2), dd(x, y), 360 - theta));
            points.push_back(rotate(dd(x - w2, y - h2), dd(x, y), 360 - theta));
            points.push_back(rotate(dd(x + w2, y - h2), dd(x, y), 360 - theta));
            tri += h * w;

        }
        vdd ch = convexHull(points);
        total = polygonArea(ch);
        cout << fixed << setprecision(1) << (tri / total) * 100 << " %\n";

    }
    return 0;
}
