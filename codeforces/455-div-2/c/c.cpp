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

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    ll n; cin >> n;
    string p;
    forn(i, n) {
        char c; cin >> c;
        p += c;
    }
    vvi dp(n, vi(n + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i < n; i++) {
            if(p[i - 1] == 'f') {
                for(int j = 1; j < n; j++) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

            } else {
                for(int j = n - 1; j >= 0; j--)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
            }

    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;

    return 0;
}
