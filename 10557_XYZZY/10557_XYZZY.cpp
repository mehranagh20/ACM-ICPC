//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vi vis;
void dfs(int i, vvi &graph) {
    vis[i] = 1;
    for(auto &e : graph[i]) if(!vis[e])
            dfs(e, graph);
}

int main() {
    int n, tc = 0;
    while(cin >> n && n != -1) {
        tc++;
        vi costs(n), dis(n, -inf); dis[0] = 100;
        vvi graph(n);
        for(int i = 0; i < n; i++) {
            int c, m; cin >> c >> m;
            costs[i] = c;
            for(int j = 0; j < m; j++) {
                int v; cin >> v; v--;
                graph[i].push_back(v);
            }
        }
        for(int i = 0; i < n - 1; i++)
            for(int j = 0; j < n; j++) for(auto &e : graph[j])
                    if(dis[j] + costs[e] > 0 && dis[j] + costs[e] > dis[e]) dis[e] = costs[e] + dis[j];
        vis.clear(); vis.resize(n, 0);
        dfs(0, graph);
        vi conn = vis;

        if(dis[n - 1] < 0) {
            bool posCir = false;
            for(int i = 0; i < n && !posCir; i++) for(auto &e : graph[i])
                    if(dis[e] < dis[i] + costs[e] && dis[i] + costs[e] > 0) {
                        vis.clear(); vis.resize(n, 0);
                        dfs(i, graph);
                        if(vis[n - 1] && conn[i]) {
                            posCir = true;
                            break;
                        }
                    }

            if(!posCir) cout << "hopeless\n";
            else cout << "winnable\n";
        }
        else cout << "winnable\n";
    }
    return 0;
}
