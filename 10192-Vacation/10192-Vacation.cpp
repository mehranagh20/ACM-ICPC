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

#define inf 1000000000
#define eps 1e-9

vvi memo;
string a, b;

int lcs() {
    int n = a.size(), m = b.size();

    for(int i = 1; i <= n; i++) memo[i][0] = 0;
    for(int i = 1; i <= m; i++) memo[0][i] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            memo[i][j] = memo[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 1 : -inf);
            memo[i][j] = max(memo[i][j], memo[i - 1][j]);
            memo[i][j] = max(memo[i][j], memo[i][j - 1]);
        }
    }
    return memo[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    int tc = 1;
    while(getline(cin, a) && a != "#") {
        getline(cin, b);
        memo.assign(a.size() + 10, vi(b.size() + 10, 0));
        int ans = lcs();
        cout << "Case #" << tc++ << ": ";
        cout << "you can visit at most " << ans << " cities." << endl;

    }


    return 0;
}
