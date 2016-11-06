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

vector<vector<char>> grid;
vector<vector<bool>> pos, articulation_vertex;
vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int m, n;
ii r, s;


vvi dfs_low, dfs_num;
vvii dfs_parent;
vvii AdjList;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int k, int d) {
    dfs_low[k][d] = dfs_num[k][d] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (auto &e : moves) {
        int u = k + e.first, v = e.second;
        if (dfs_num[u][v] == 0) { // a tree edge
            dfs_parent[u][v] = ii(k, d);
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(u, v);
            if (dfs_low[u][v] >= dfs_num[k][d]) // for articulation point
                articulation_vertex[k][d] = true;
            if (dfs_low[u][v] > dfs_num[k][d]) // found a bridge
                ;// bridges are here, use them as you want.
            dfs_low[k][d] = min(dfs_low[k][d], dfs_low[u][v]);
        } else if (ii(u, v) != dfs_parent[k][d]) // a back edge and not direct cycle
            dfs_low[k][d] = min(dfs_low[k][d], dfs_num[u][v]);
    }
}

void articulationPointAndBridge(int u) {

}

void dfs(int i, int j) {
    if(i < 0 || i >= m || j < 0 || j >= n) return;
    if(grid[i][j] == 'o' || pos[i][j]) return;
    pos[i][j] = true;
    for(auto &e : moves) dfs(i + e.first, j + e.second);
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> m >> n && (n || m)) {
        grid.clear(); grid.resize(m, vector<char>(n));
        pos.clear(); pos.resize(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'r') r.first = i, r.second = j;
                if(grid[i][j] == 's') s.first = i, r.second = j;
            }
        dfs(r.first, r.second);

    }

    return 0;
}