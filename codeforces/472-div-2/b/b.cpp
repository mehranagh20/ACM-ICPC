//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<ld, ld> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
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

vvi graph;

int n, m;

vi vis;
void dfs(int i, si &r, si &c) {
    if(vis[i]) return;
    vis[i] = 1;
    if(i < n) r.insert(i);
    else c.insert(i);

    for(auto &e: graph[i]) if(!vis[e])
            dfs(e, r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    vs g(n);
    for(auto &e: g) cin >> e;
    graph.assign(n + m, vi());
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(g[i][j] == '#') graph[i].push_back(j + n), graph[j + n].push_back(i);
        }

    vs gg(n, string(m, '.'));
    vis.assign(n + m, 0);
    for(int i = 0; i < n; i++) {
        si r, c;
        dfs(i, r, c);
        for(auto &e: r) for(auto &ee: c)
                gg[e][ee - n] = '#';

    }
    if(gg == g) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}