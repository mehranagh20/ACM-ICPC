//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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

#define inf 1000000000
#define eps 1e-9
#define EXPLORED 2
#define UNVISITED 0
#define VISITED 1

vi dfs_num, dfs_parent;
vvii AdjList;


bool graphCheck(int u) {
// DFS for checking graph edge properties
    dfs_num[u] = EXPLORED;
// color u as EXPLORED instead of VISITED
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) { // Tree Edge, EXPLORED->UNVISITED
            dfs_parent[v.first] = u;
// parent of this children is me
            if(graphCheck(v.first)) return true;
        }
        else if (dfs_num[v.first] == EXPLORED) {
            AdjList[u][j].second++;
// EXPLORED->EXPLORED
            if (v.first == dfs_parent[u]);
// to differentiate these two cases
                //printf(" Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
            else {
// the most frequent application: check if the graph is cyclic
                //printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);

            }
        }
        else if (dfs_num[v.first] == VISITED)
            return true;
// EXPLORED->VISITED
           // printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
    }
    dfs_num[u] = VISITED;
// after recursion, color u as VISITED (DONE)
    return false;
}


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        AdjList.clear(); AdjList.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            AdjList[a].push_back(ii(b, 0));
        }
        bool cac = true;
        int numScc = 0;
        dfs_num.clear(); dfs_num.resize(n, UNVISITED);
        dfs_parent.clear(); dfs_parent.resize(n, 0);
        for(int i = 0; i < n; i++) {
            if(dfs_num[i] == UNVISITED) {
                numScc++;
                if(graphCheck(i)) {
                    cac = false;
                    break;
                }
            }
        }
        if(cac && numScc == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
