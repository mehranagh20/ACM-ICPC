//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vvi graph;

void dfs(int i, vi &vis) {
    vis[i] = 1;
    for(auto &e : graph[i]) if(!vis[e]) dfs(e, vis);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m) {
        graph.clear(); graph.resize(n);
        bool pos = false;
        vi vis(n, 1);
        for(int i = 0; i < m; i++) {
            pos = true;
            int a, b; cin >> a >> b;
            vis[a] = vis[b] = 0;
            graph[a].push_back(b), graph[b].push_back(a);
        }
        for(int i = 0; i < graph.size(); i++) if(graph[i].size() % 2) {
                pos = false; break;
            }
        int components = 0;
        for(int i = 0; i < n; i++) if(!vis[i]) {
                components++;
                if(components > 1) {
                    pos = false; break;
                }
                dfs(i, vis);
            }
        if(pos) cout << "Possible\n";
        else cout << "Not Possible\n";
    }


    return 0;
}