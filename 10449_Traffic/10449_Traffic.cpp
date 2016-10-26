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

void dfs(int a, vvii &graph) {
    vis[a] = 1;
    for(auto &e : graph[a]) if(!vis[e.first])
        dfs(e.first, graph);
}

int main() {
    int n, r, tc = 1;
    while(cin >> n) {
        vi busyness(n);
        vvii graph(n);
        for(int i = 0; i < n; i++) cin >> busyness[i];
        cin >> r;
        for(int i = 0; i < r; i++) {
            int a, b; cin >> a >> b; a--; b--;
            graph[a].push_back(ii(b, busyness[b] - busyness[a]));
        }

        int q; cin >> q;
        vi dis(n, inf);
        if(q) {
            dis[0] = 0;
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n; j++)
                    for (auto &e : graph[j])
                        if(dis[j] != inf) dis[e.first] = min(dis[e.first], (int)pow(e.second, 3) + dis[j]);
        }

        vis.clear(); vis.resize(n, 0);
        for(int i = 0; i < n; i++) for(auto &e : graph[i]) {
                if((int)pow(e.second, 3) + dis[i] < dis[e.first] && !vis[i]) {
                    dfs(i, graph);
                }
            }

        cout << "Set #" << tc++ << endl;
        for(int i = 0; i < q; i++) {
            int a; cin >> a; a--;
            int ans = vis[a] ? 0 : dis[a];
            if(ans < 3 || ans == inf) cout << "?\n";
            else cout << ans << endl;
        }
    }

    return 0;
}
