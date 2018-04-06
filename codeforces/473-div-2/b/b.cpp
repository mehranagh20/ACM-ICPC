
//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    int n, k, m; cin >> n >> k >> m;
    map<string, ll> mp;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s] = i + 1;
    }
    vi c(n);
    for(auto &e: c) cin >> e;
    vi gp(n + 1);
    vi gps(k, inf);
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            int k; cin >> k;
            gp[k] = i;
            gps[i] = min(gps[i], c[k - 1]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        string cur; cin >> cur;
        int g = gp[mp[cur]];
        ans += gps[g];
    }

    cout << ans << endl;

    return 0;
}