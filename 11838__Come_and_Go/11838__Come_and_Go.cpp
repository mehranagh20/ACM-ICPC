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
vi dfs_num, dfs_low, scc, vis;
int counter, root;

bool dfs(int s) {
    dfs_low[s] = dfs_num[s] = counter++; scc.push_back(s);
    vis[s] = 1;
    for(auto &e : graph[s]) {
        if (dfs_num[e] == inf) if(!dfs(e)) return false;
        if(vis[e]) dfs_low[s] = min(dfs_low[s], dfs_low[e]);
    }
    if(dfs_low[s] == dfs_num[s]) {
        if(s != root)
            return false;
        while(1) {
            int tmp = scc.back(); scc.pop_back();
            vis[tmp] = 0;
            if(tmp == s) break;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m && (n || m)) {
        graph.clear(); graph.resize(n);
        dfs_num.clear(); dfs_num.resize(n, inf);
        dfs_low.clear(); dfs_low.resize(n);
        vis.clear(); vis.resize(n, 0);
        scc.clear();
        counter = 0;
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            if(c == 1) graph[a - 1].push_back(b - 1);
            else {
                graph[a - 1].push_back(b - 1);
                graph[b - 1].push_back(a - 1);
            }
        }
        root = 0;
        if(!dfs(0)) cout << "0\n";
        else {
            bool found = false;
            for(int i = 0; i < n; i++) if(dfs_num[i] == inf) {
                    cout << "0\n";
                    found = true;
                    break;
                }
            if(!found) cout << "1\n";
        }
    }

    return 0;
}