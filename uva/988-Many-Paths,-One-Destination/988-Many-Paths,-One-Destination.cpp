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

void topSort(vi &order, int n, vi &vis, vvi &graph) {
    vis[n] = 1;
    for(auto &e : graph[n]) if(!vis[e]) topSort(order, e, vis, graph);
    order.push_back(n);
}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 0;
    while(cin >> n && n) {
        if(tc++) cout << endl;
        vvi graph(n);
        for(int i = 0; i < n; i++) {
            int nn; cin >> nn;
            for(int j = 0; j < nn; j++) {
                int tmp; cin >> tmp;
                graph[i].push_back(tmp);
            }
        }
        vi order, vis(n, 0), ways(n, 0);
        ways[0] = 1;
        topSort(order, 0, vis, graph);
        int ans = 0;
        for(int i = order.size() - 1; i >= 0; i--) {
            int n = order[i];
            if(graph[n].size() == 0) ans += ways[n];
            for(auto &e : graph[n]) ways[e] += ways[n];
        }
        cout << ans << endl;
    }

    return 0;
}