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

dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }

dd scale(dd v, double s) { return dd(v.first * s, v.second * s); }

dd translate(dd p, dd v) { return dd(p.first + v.first , p.second + v.second); }

double dot(dd a, dd b) { return (a.first * b.first + a.second * b.second); }

double dist(dd p1, dd p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

double norm_sq(dd v) { return v.first * v.first + v.second * v.second; }

double distToLine(dd p, dd a, dd b) {
    dd ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    dd c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance between p and c
}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 0;
    while(cin >> n && n) {
        vdd pol(n);
        for(auto &e : pol) cin >> e.first >> e.second;
        vdd ch = convexHull(pol);
        double ans = inf;
        for(int i = 0; i < ch.size() - 1; i++) {
            double max_now = 0;
            for(int j = 0; j < ch.size(); j++)
                max_now = max(max_now, distToLine(ch[j], ch[i], ch[i + 1]));
            ans = min(ans, max_now);
        }
        cout << "Case " << ++tc << ": " << fixed << setprecision(2) << ans << endl;

    }


    return 0;
}
