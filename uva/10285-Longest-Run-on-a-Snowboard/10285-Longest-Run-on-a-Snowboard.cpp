//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

vii moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;

vii order;
vvi vis;
void topSort(int i, int j, vvi &grid) {
    vis[i][j] = 1;
    for(auto &e : moves) {
        if(i + e.first < 0 || i + e.first >= m || j + e.second < 0 || j + e.second >= n) continue;
        if(!vis[i + e.first][j + e.second] && grid[i + e.first][j + e.second] < grid[i][j]) topSort(i + e.first, j + e.second, grid);
    }
    order.push_back(ii(i, j));
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        string name; cin >> name >> m >> n;
        vvi grid(m, vi(n));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
        order.clear(); vis.clear(); vis.resize(m, vi(n, 0));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(!vis[i][j]) topSort(i, j, grid);
        vii rOrder; for(int i = order.size() - 1; i >= 0; i--) rOrder.push_back(order[i]);
        vvi dis(m, vi(n, 0));
        int ans = 0;
        for(auto &e : rOrder) {
            int i = e.first, j = e.second;
            for(auto &e : moves) {
                if(e.first + i < 0 || e.first + i >= m || e.second + j < 0 || e.second + j >= n || grid[i][j] <= grid[i + e.first][j + e.second]) continue;
                dis[i + e.first][j + e.second] = max(dis[i][j] + 1, dis[i + e.first][j + e.second]);
                ans = max(ans, dis[i + e.first][j + e.second]);
            }
        }
        cout << name << ": " << ans + 1 << endl;
    }

    return 0;
}