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

int n, m;
vvi graph;

vi bfs(int i) {
    vi dis(n, inf); dis[i] = 0;
    vi vis(n, 0); vis[i] = 1;
    queue<int> q; q.push(i);

    while(q.size()) {
        int cur = q.front(); q.pop();
        for(auto &e: graph[cur]) {
            if(!vis[e]) {
                vis[e] = 1;
                q.push(e);
                dis[e] = dis[cur] + 1;
            }

        }

    }
    return dis;
}

int main() {
    cin >> n >> m;
    int s, t; cin >> s >> t;
    graph.assign(n, vi());
    vvi ed(n, vi(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        ed[a][b] = ed[b][a] = 1;
    }

    s--, t--;
    vi h = bfs(s), w = bfs(t);

    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            if(!ed[i][j]) {
                if((h[j] + w[i] + 1 >= h[t]) && (h[i] + w[j] + 1 >= h[t]))
                    ans++;

            }

        }
    cout << ans << endl;


    return 0;
}

