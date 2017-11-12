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

vii moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vvvi grid;
int n, m;

int bfs() {
    vvvi dis(4, vvi(n, vi(m, inf)));
    dis[0][0][0] = 0;
    queue<iii> q;
    q.push(iii(0, ii(0, 0)));
    while(!q.empty()) {
        iii now = q.front(); q.pop();
        int x = now.second.first, y = now.second.second, lvl = now.first;
        int cur_dis = dis[lvl][x][y];
        for(auto &tmp_nei: grid[x][y]) {
            int nei = (tmp_nei + lvl) % 4;
            int nei_x = x + moves[nei].first, nei_y = y + moves[nei].second;
            if(nei_x < 0 || nei_x >= n || nei_y < 0 || nei_y >= m || dis[(lvl + 1) % 4][nei_x][nei_y] != inf) continue;
            dis[(lvl + 1) % 4][nei_x][nei_y] = cur_dis + 1;
            if(nei_x == n - 1 && nei_y == m - 1) return cur_dis + 1;
            q.push(iii((lvl + 1) % 4, ii(nei_x, nei_y)));
        }
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(0);
    map<char, int> mp = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    while(cin >> n >> m) {
        grid.assign(n, vvi(m, vi(0)));
        for(int i = 0; i < n - 1; i++) for(int j = 0; j < m; j++) {
            string str; cin >> str;
            for(auto &c: str) grid[i][j].push_back(mp[c]);
        }
        for(int j = 0; j < m - 1; j++) {
            string str; cin >> str;
            for(auto &c: str) grid[n - 1][j].push_back(mp[c]);
        }
        int ans = bfs();
        if(ans == inf) cout << "no path to exit" << endl;
        else cout << ans << endl;
    }


    return 0;
}
