//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vi par, vis;
vii cycle;
vvi graph;
int n, m;
ii removed = ii(-1, -1);

bool dfs(int u) {
  // cout << u << endl;
  vis[u] = 1;
  for(auto &e: graph[u]) {
    if(removed == ii(u, e)) continue;
    if(vis[e] == 0) {
      par[e] = u;
      if(dfs(e)) return true;
    }
    else if(vis[e] == 1) {
      if(removed == ii(-1, -1)) {
        cycle.push_back(ii(u, e));
        int cur = u;
        while(par[cur] != e) {
          cycle.push_back(ii(par[cur], cur));
          cur = par[cur];
          if(cur == -1) break;
        }
        cycle.push_back(ii(e, cur));
      }
      return true;
    }
  }
  vis[u] = 2;
  return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--, b--;
      graph[a].push_back(b);
    }
    vis.resize(n, 0), par.resize(n, -1);
    bool ok = true;
    for(int i = 0; i < n; i++) if(vis[i] == 0) {
      if(dfs(i)) ok = false;
    }
    if(ok) cout << "YES" << endl;
    else {
      for(auto &e: cycle) {
        removed = e;
        ok = true;
        vis.assign(n, 0);
        for(int i = 0; i < n; i++) if(vis[i] == 0) {
          if(dfs(i)) ok = false;
        }
        if(ok) {
          cout << "YES" << endl;
          return 0;
        }
      }
      cout << "NO" << endl;
    }

    return 0;
}