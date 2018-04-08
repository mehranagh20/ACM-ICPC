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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    ll n, w, b, x; cin >> n >> w >> b >> x;
    ll bsum = 0;
    vi brds(n), cost(n);
    for(auto &e: brds) cin >> e, bsum += e;
    for(auto &e: cost) cin >> e;

    vvi dp(n + 1, vi(bsum + 10, -inf));
    for(ll i = 0; i <= brds[0]; i++)
        dp[1][i] = w - i * cost[0];

    int til = brds[0] + brds[1];

    for(ll i = 2; i <= n; i++) {
        for(ll j = 0; j <= til; j++) {
            for(ll k = 0; k <= min(j, brds[i - 1]); k++)
                if(dp[i - 1][j - k] >= 0)
                    dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k] + x, w + b * (j - k)) - k * cost[i - 1]);
        }
        til += brds[i];
    }

    int ans = 0;
    for(int i = 1; i <= bsum; i++) if(dp[n][i] >= 0)
            ans = i;

    cout << ans << endl;


    return 0;
}

