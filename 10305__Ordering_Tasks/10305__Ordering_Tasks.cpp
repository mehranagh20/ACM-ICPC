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

vi ts, vis;
vvi graph;

void dfs(int n) {
    vis[n] = 1;
    for(auto &e : graph[n])
        if(!vis[e]) dfs(e);
    ts.push_back(n);
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m && (n || m)) {
        ts.clear();
        vis.clear(); vis.resize(n, 0);
        graph.clear(); graph.resize(n);
        while(m--) {
            int a, b; cin >> a >> b;
            graph[a - 1].push_back(b - 1);
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        cout << ts.back() + 1;
        for(int i = ts.size() - 2; i >= 0; i--) cout << " " << ts[i] + 1;
        cout << endl;
    }

    return 0;
}