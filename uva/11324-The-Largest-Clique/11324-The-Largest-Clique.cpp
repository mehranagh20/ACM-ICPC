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

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC, scc_num;
vvii AdjList;

vvi graph;
vvi scc;
vi node_to_scc_num;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0)
            tarjanSCC(v.first);
        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        scc.push_back(vi());
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            scc.back().push_back(v);
            node_to_scc_num[v] = scc_num;
            if (u == v) break; }
        scc_num++;
    }
 }

vi memo;
int solve(int id) {
    int &now = memo[id];
    if(now != -1) return now;
    now = 0;
    for(auto &e: graph[id]) {
        int cur = scc[e].size();
        now = max(now, solve(e) + cur);
    }
    return now;
}


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        scc.clear();
        int n, m; cin >> n >> m;
        AdjList.assign(n, vii());
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--, b--;
            if(a != b)
            AdjList[a].push_back(ii(b, 0));
        }
        int V = n;

        dfs_num.assign(V, 0); dfs_low.assign(V, 0); visited.assign(V, 0); node_to_scc_num.assign(V, -1);
        dfsNumberCounter = numSCC = scc_num = 0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == 0)
                tarjanSCC(i);

        graph.assign(scc_num, vi());
        for(int i = 0; i < scc.size(); i++) {
            for(int j = 0; j < scc[i].size(); j++) for(auto &e: AdjList[scc[i][j]])
                if(node_to_scc_num[e.first] != i) graph[i].push_back(node_to_scc_num[e.first]);
        }
        memo.assign(scc_num, -1);
        int ans = 0;
        for(int i = 0; i < scc_num; i++) {
            int cur = scc[i].size();
            ans = max(ans, solve(i) + cur);
        }
        cout << ans << endl;

    }


    return 0;
}
