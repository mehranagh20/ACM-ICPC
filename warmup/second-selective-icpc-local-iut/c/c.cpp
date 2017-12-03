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

vs grid;
int n, m;
vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void dfs(int i, int j) {
    grid[i][j] = '.';
    for(auto &e: moves) if(i + e.first < n && i + e.first >= 0 && j + e.second < m && j + e.second >= 0 && grid[i + e.first][j + e.second] == '#')
            dfs(i + e.first, j + e.second);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    grid.assign(n, "");
    for(auto &e: grid) cin >> e;
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                dfs(i, j);
                ans++;
            }
        }
    cout << ans << endl;



    return 0;
}
