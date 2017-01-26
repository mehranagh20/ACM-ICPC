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

vii fMoves = {{1, -1}, {1, 1}};

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n; cin >> n;
        vector<vector<llu>> ans(n, vector<llu>(n, 0));
        vector<vector<char>> grid(n, vector<char>(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'W') ans[i][j] = 1;
            }
        for(int i = n - 1; i >= 0; i--) for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'B') continue;
                for(auto &e : fMoves) {
                    if(i + e.first >= n || j + e.second < 0 || j + e.second >= n) continue;
                    ans[i][j] += ans[i + e.first][j + e.second];
                }
                int tmpI = i + 2, tmpJ = j + 2;
                if(tmpI < n && tmpJ < n && grid[i + 1][j + 1] == 'B') ans[i][j] += ans[tmpI][tmpJ];
                tmpJ = j - 2;
                if(tmpI < n && tmpJ >= 0 && grid[i + 1][j - 1] == 'B') ans[i][j] += ans[tmpI][tmpJ];
                ans[i][j] %= 1000007;
            }
        llu an = 0;
        for(int i = 0; i < n; i++) an += ans[0][i];
        cout << "Case " << i << ": " << an % 1000007 << endl;
    }

    return 0;
}