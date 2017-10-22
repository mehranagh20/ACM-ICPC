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

double cross(dd a, dd b) { return a.first * b.second - a.second * b.first; }
dd toVec(dd a, dd b) { return dd(b.first - a.first, b.second - a.second); }
bool ccw(dd p, dd q, dd r) { return cross(toVec(p, q), toVec(p, r)) > eps; }

ll solve(vi &l, vi &r) {
    ll ans = 0;
    for(auto &e: l) for(auto &ee: r) ans += e * ee;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        vii points;
        vi costs;
        for(int i = 0; i < n; i++) {
            int a, b, c; cin >> c >> a >> b;
            points.push_back(ii(a, b));
            costs.push_back(c);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                vi l, r;
                for(int k = 0; k < n; k++) if(k != i && k != j) {
                        if(ccw(points[i], points[j], points[k])) l.push_back(costs[k]);
                        else r.push_back(costs[k]);
                    }
                l.push_back(costs[i]);
                r.push_back(costs[j]);
                ans = max(ans, solve(l, r));

                l.pop_back(), r.pop_back();
                l.push_back(costs[i]), l.push_back(costs[j]);
                ans = max(ans, solve(l, r));

                l.pop_back(), l.pop_back();
                r.push_back(costs[i]), r.push_back(costs[j]);
                ans = max(ans, solve(l, r));

                r.pop_back(), r.pop_back();
                l.push_back(costs[j]), r.push_back(costs[i]);
                ans = max(ans, solve(l, r));


            }
        }
        cout << ans << endl;
    }



    return 0;
}
