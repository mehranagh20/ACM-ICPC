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

string str;
vvvvi memo;
vs grid;
vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
map<char, int> mp;
int n, m;
int solve(int i, int j, int k, int d) {
    if(d > n * m) return inf;
    int &ans = memo[d][i][j][k];
    if(ans != -1) return ans;
    ans = inf;
    if(grid[i][j] == 'E')
        return 0;
    for(auto &e: moves) {
        if(i + e.first < 0 || i + e.first >= n || j + e.second < 0 || j + e.second >= m || grid[i + e.first][j + e.second] == '#')
            continue;
        ans = min(solve(i + e.first, j + e.second, k, d +  1) + 1, ans);
    }
    if(k < str.size()) {
        ii e = moves[mp[str[k]]];
        if((i + e.first < 0 || i + e.first >= n || j + e.second < 0 || j + e.second >= m || grid[i + e.first][j + e.second] == '#')) {
            e = ii(0, 0);
        }
        ans = min(ans, solve(i + e.first, j + e.second, k + 1, d));
        ans = min(ans, solve(i, j, k + 1, d) + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    mp['D'] = 0;
    mp['R'] = 1;
    mp['L'] = 3;
    mp['U'] = 2;

    cin >> n >> m;
    grid.assign(n, "");
    for(auto &e: grid) cin >> e;
    cin >> str;
    int k, r;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j] == 'R') k = i, r = j;
    memo.resize(100, vvvi(n + 1, vvi(m + 1, vi(str.size() + 1, -1))));
    //cout<<solve(3,3 , 1) << endl;
    cout << solve(k, r, 0, 0) << endl;
    // for(int i = 0; i < n; i++)
    //     for (int l = 0; l < m; ++l) {
    //         cout << i << " "<<l  << " " << memo[i][l][0]<<endl;
    //     }

/*
 * 4 5
.##..
.R#..
.##.E
....#
L
 */

    return 0;
}
