//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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

#define inf 1000000000
#define eps 1e-9

vi dist, work;
int s, t, n;
vvi rem, graph;

bool dinic_bfs() {
    dist.clear(); dist.resize(n, -1); dist[s] = 0;
    queue<int> queue1; queue1.push(s);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        for(auto &e : graph[u]) {
            if(dist[e] != -1 || rem[u][e] <= 0) continue;
            dist[e] = dist[u] + 1;
            queue1.push(e);
        }
    }
    return (dist[t] != -1);
}

int dinic_dfs(int u, int f) {
    if(u == t) return f;
    for(int &i = work[u]; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(rem[u][v] <= 0) continue;
        if(dist[u] + 1 == dist[v]) {
            int df = dinic_dfs(v, min(f, rem[u][v]));
            if(df > 0) {
                rem[v][u] += df;
                rem[u][v] -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int result = 0;
    while(dinic_bfs()) {
        work.clear(); work.resize(n, 0);
        while(int d = dinic_dfs(s, inf)) result += d;
    }
    return result;
}

void dfs(vi &vis, int a) {
    vis[a] = 1;
    for(auto &e : graph[a]) if(!vis[e] && rem[a][e]) dfs(vis, e);
}

int main() {
    ios::sync_with_stdio(0);
    int w, m;
    while(cin >> w >> m && (w || m)) {
        s = 0, t = w - 1;
        graph.clear(); graph.resize(w * 2);
        rem.clear(); rem.resize(w * 2, vi(w * 2, 0));
        graph[s].push_back(s + w); graph[s + w].push_back(s);
        rem[s][s + w] = inf;
        graph[t].push_back(t + w); graph[t + w].push_back(t);
        rem[t][t + w] = inf;
        t = t + w;
        for(int i = 1; i < w - 1; i++) {
            int a, b; cin >> a >> b; a--;
            graph[a].push_back(a + w), graph[a + w].push_back(a);
            rem[a][a + w] = b;
        }
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            graph[a + w].push_back(b); graph[b].push_back(a + w);
            graph[b + w].push_back(a); graph[a].push_back(b + w);
            rem[a + w][b] = rem[b + w][a] = c;
        }
        n = graph.size();
        cout << maxFlow() << endl;
    }

    return 0;
}