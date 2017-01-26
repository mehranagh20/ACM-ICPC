//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vvi grid, vis;
vector<vvvi> memo;
int n;

int sol(int i, int j, int k, int w) { // w = 0 from up, 1 coming from left, 2 coming from right
    if(k < 0) return -inf;
    if(i == n - 1 && j == n - 1) return 0;
    int &t = memo[i][j][k][w], tmp;
    if(t != -inf) return t;
    t = -inf - 1;
    if(i + 1 < n) {
        tmp = sol(i + 1, j, grid[i + 1][j] < 0 ? k - 1 : k, 0);
        if(tmp > -inf) t = max(t, tmp + grid[i + 1][j]);
    }
    if(w == 1 || w == 0) if(j + 1 < n) {
            tmp = sol(i, j + 1, grid[i][j + 1] < 0 ? k - 1 : k, 1);
            if(tmp > -inf) t = max(t, tmp + grid[i][j + 1]);
        }
    if(w == 2 || w == 0) if(j - 1 >= 0) {
            tmp = sol(i, j - 1, grid[i][j - 1] < 0 ? k - 1 : k, 2);
            if(tmp > -inf) t = max(t, tmp + grid[i][j - 1]);
        }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    int k, tc = 1;
    while(cin >> n >> k && (n || k)) {
        grid.clear(); grid.resize(n, vi(n));
        memo.clear(); memo.resize(n, vvvi(n, vvi(k + 1, vi(3, -inf))));
        vis.clear(); vis.resize(n, vi(n, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
        vis[0][0] = 1;
        int ans = sol(0, 0, grid[0][0] < 0 ? k - 1 : k, 1);
        cout << "Case " << tc++ << ": ";
        if(ans <= -inf) cout << "impossible\n";
        else cout << ans + grid[0][0] << endl;
    }

    return 0;
}