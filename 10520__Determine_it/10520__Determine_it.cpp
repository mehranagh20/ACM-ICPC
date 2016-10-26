#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vector<vector<ll>> memo;
int n, a;

ll solve(int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    if(i >= j) {
        ll fMx = 0, sMx = 0;
        for(int k = 1; k < j; k++)
            fMx = max(fMx, solve(i, k) + solve(n, k));
        for(int k = i + 1; k <= n; k++)
            sMx = max(sMx, solve(k, 1) + solve(k, j));
        return memo[i][j] = fMx + sMx;
    }
    else {
        ll mx = -inf;
        for(int k = i; k < j; k++)
            mx = max(mx, solve(i, k) + solve(k + 1, j));
        return memo[i][j] = mx;
    }
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> a) {
        memo.clear(); memo.resize(n + 10, vector<ll>(n + 1, -1));
        memo[n][1] = a;
        cout << solve(1, n) << endl;
    }

    return 0;
}