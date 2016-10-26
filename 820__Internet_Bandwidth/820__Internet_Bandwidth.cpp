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
vvi rem;
vi par;
int s, t, f;

void augment(int v, int minEdge) {
    if(v == s) {
        f = minEdge; return;
    }
    if(par[v] != -1) {
        augment(par[v], min(minEdge, rem[par[v]][v]));
        rem[par[v]][v] -= f; //rem[v][par[v]] += f;
    }
}

int main() {
    int n, tc = 0;
    while(cin >> n && n) {
        int m; cin >> s >> t >> m; s--; t--;
        rem.clear(); rem.resize(n, vi(n, 0));
        vvi graph(n);
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
            rem[a][b] += c;
            rem[b][a] += c;
        }
        int maxFlow = 0;
        while(1) {
            f = 0;
            par.clear(); par.resize(n, -1);
            bitset<101> vis; vis[s] = 1;
            queue<int> queue1; queue1.push(s);
            while(!queue1.empty()){
                int u = queue1.front(); queue1.pop();
                if(u == t) break;
                for(auto &e : graph[u]) if(!vis[e] && rem[u][e] > 0) {
                        vis[e] = 1; par[e] = u;
                        queue1.push(e);
                    }
            }
            augment(t, inf);
            if(!f) break;
            maxFlow += f;
        }
        cout << "Network " << ++tc << endl;
        cout << "The bandwidth is " << maxFlow << "." << endl << endl;
    }

}
