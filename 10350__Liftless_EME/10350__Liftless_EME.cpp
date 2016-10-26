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

vii moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;

vi order;
vi vis;
void topSort(int i, vvii &graph) {
    vis[i] = 1;
    for(auto &e : graph[i]) if(!vis[e.first]) topSort(e.first, graph);
    order.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    string name;
    while(cin >> name) {
        int n, m; cin >> n >> m;
        vvii graph; graph.resize(n * m);
        for(int i = 0; i < n - 1; i++) for(int j = 0; j < m; j++)
                for(int k = 0; k < m; k++) {
                    int tmp; cin >> tmp;
                    graph[i * m + j].push_back(ii((i + 1) * m + k, tmp));
                }
        order.clear(); vis.clear(); vis.resize(n * m, 0);
        for(int i = 0; i < n * m; i++) if(!vis[i]) topSort(i, graph);
        vi dis(n * m, inf); for(int i = 0; i < m; i++) dis[i] = 0;
        for(int i = order.size() - 1; i >= 0; i--) {
            int tm = order[i];
            for(auto &e : graph[tm]) dis[e.first] = min(dis[e.first], dis[tm] + e.second);
        }
        int ans = inf;
        for(int i = n * m - m; i < n * m; i++) ans = min(ans, dis[i]);
        cout << name << endl << ans + (n - 1) * 2 << endl;
    }

    return 0;
}