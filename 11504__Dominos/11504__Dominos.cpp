//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vvi graph;
vi dfs_num, dfs_low, scc, vis, indegree;
vector<string> numToString;
int n, counter, m, root, ans;

void dfs(int s) {
    dfs_low[s] = dfs_num[s] = counter++; scc.push_back(s);
    vis[s] = 1;
    for(auto &e : graph[s]) {
        if (dfs_num[e] == inf) dfs(e);
        indegree[e]--;
        if(vis[e]) dfs_low[s] = min(dfs_low[s], dfs_low[e]);
    }
    if(dfs_low[s] == dfs_num[s]) {
        bool add = true;
        while(true) {
            int tmp = scc.back(); scc.pop_back();
            vis[tmp] = 0;
            if(indegree[tmp] > 0) add = false;
            if (tmp == s) break;
        }
        if(add) ans++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        graph.clear(); graph.resize(n);
        indegree.clear(); indegree.resize(n, 0);
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a - 1].push_back(b - 1);
            indegree[b - 1]++;
        }
        vis.clear(); vis.resize(n, 0);
        scc.clear();
        dfs_low.clear(); dfs_low.resize(n);
        dfs_num.clear(); dfs_num.resize(n, inf);
        counter = ans = 0;
        for(int i = 0; i < n; i++) if(dfs_num[i] == inf)
                dfs(i);
        cout << ans << endl;
    }

    return 0;
}