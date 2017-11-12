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

int main() {
    ios::sync_with_stdio(0);
    ll n, m;
    while(cin >> n >> m && (n || m)) {
        vector<pair<ll, ll>> coors(n);
        for(auto &e: coors) cin >> e.first >> e.second;
        vector<vector<ll>> dis(n, vector<ll>(n));
        vector<ll> alldis(40002, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ll d = (coors[i].first - coors[j].first) * (coors[i].first - coors[j].first)
                    + (coors[i].second - coors[j].second) * (coors[i].second - coors[j].second);
                    d = ceil(sqrt(d)) + eps;
                    alldis[d] += 1;
                }

        }
        for(int i = 1; i < 40002; i++) alldis[i] += alldis[i - 1];
        for(int i = 0; i < m; i++) {
            ll r; cin >> r;
            ll num = alldis[r];

            cout << fixed << setprecision(2) << (double)num / n << endl;
        }
        cout << endl;
    }


    return 0;
}
