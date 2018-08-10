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
typedef vector<int> vi;
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
    int n; cin >> n;
    vi h(n + 1);
    forn(i, n + 1) if(i) cin >> h[i];
    h.push_back(0);
    vvvi dp(n / 2 + 10, vvi(n + 1, vi(2, inf)));

    forn(i, n) forn(j, 2)
      dp[0][i][j] = 0;
    forn(i, n / 2 + 2) forn(j, 2)
      dp[i][0][j] = inf;

    forn(i, n / 2 + 2) if(i)
      forn(j, n + 1) if(j) {
        // k = 0
        int cst = 0;
        dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j - 1][1]);
        cst += max(0, h[j - 1] - h[j] + 1);
        cst += max(0, h[j + 1] - h[j] + 1);
        dp[i][j][0] = min(min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + cst, dp[i][j][0]);

        if(j >= 3) {
          dp[i][j][1] = min(dp[i][j - 2][1], dp[i][j - 2][0]);
          cst = max(0, min(h[j - 1], h[j - 2] - 1) - h[j] + 2) + max(0, h[j + 1] - h[j] + 1);
          dp[i][j][1] = min(dp[i][j][1], min(dp[i - 1][j - 2][0], dp[i - 1][j - 2][1]) + cst);
        }
      }
    int to = n / 2 + (n % 2);
    forn(i, to + 1) if(i) {
      int mn = inf;
      forn(j, n + 1) if(j) forn(k, 2)
          mn = min(mn, dp[i][j][k]);
      cout << mn << " ";
    }
    cout << endl;

    return 0;
}
