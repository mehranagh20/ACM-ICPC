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

vii moves = {{1,  0},
             {0,  1},
             {-1, 0},
             {0,  -1}};

vi dfs_low, dfs_num, dfs_parent, articulation_vertex;
vvii AdjList;
int dfsNumberCounter, dfsRoot, rootChildren;


void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int) AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0) { // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; // store this information first
            if (dfs_low[v.first] > dfs_num[u]) // for bridge
                printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
        } else if (v.first != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]); // update dfs_low[u]
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
        int ans = 0;
        vvii degree(5);
        while (true) {
            int minDeg = inf;
            pair<int, int> tmpAns = {-1, -1};
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != '*') continue;
                    int tmp = 0;
                    for (auto &e : moves) {
                        if (i + e.first < 0 || i + e.first >= m || j + e.second < 0 || j + e.second >= n ||
                            grid[i + e.first][j + e.second] != '*')
                            continue;
                        tmp++;
                    }
                    if (tmp < minDeg) {
                        minDeg = tmp;
                        tmpAns = {i, j};
                    }
                }
            if (tmpAns == ii(-1, -1)) break;
            grid[tmpAns.first][tmpAns.second] = 'o';
            ans++;
            int i = tmpAns.first, j = tmpAns.second;
            for (auto &e : moves) {
                if (i + e.first < 0 || i + e.first >= m || j + e.second < 0 || j + e.second >= n ||
                    grid[i + e.first][j + e.second] != '*')
                    continue;
                grid[i + e.first][j + e.second] = 'o';
                break;
            }
        }
        cout << ans << endl;


    }

    return 0;
}