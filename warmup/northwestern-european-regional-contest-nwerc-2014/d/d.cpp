//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

string state;
vvi graph;
vi topsort;

void dfs(int i, vi &vis) {
    vis[i] = 1;
    for(auto &e: graph[i]) if(!vis[e])
            dfs(e, vis);
    topsort.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    ll n, m;
    while(cin >> n >> m) {
        state.clear();
        graph.assign(m + 1, vi());
        for (int i = 1; i <= m; ++i) {
            char c;
            int a, b; cin >> c >> a >> b;
            state += c;
            graph[i].push_back(a), graph[i].push_back(b);
        }
        topsort.clear();
        vi vis(m + 1, 0);
        dfs(1, vis);
        vis.assign(m + 1, 0);
        vis[1] = n;
        for(int i = topsort.size() - 1; i >= 0; i--) {
            ll v = topsort[i];
            if(v == 0) continue;
            ll nn = vis[v];
            ll a = nn / 2, b = nn / 2;
            if(state[v - 1] == 'L') a += nn % 2;
            else b += nn % 2;
            if(nn % 2) state[v - 1] = (state[v - 1] == 'L' ? 'R' : 'L');
            vis[graph[v][0]] += a, vis[graph[v][1]] += b;
        }
        cout << state << endl;
    }


    return 0;
}
