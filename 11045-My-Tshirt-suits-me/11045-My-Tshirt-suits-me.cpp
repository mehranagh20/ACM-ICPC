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
vvi graph, rem;

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

int main() {
    s = 0, t = 1;
    int tc; cin >> tc;
    map<string, int> mp = {{"XXL", 2}, {"XL", 3}, {"L", 4}, {"M", 5} , {"S", 6}, {"XS", 7}};
    while(tc--) {
        int nn, m; cin >> nn >> m; nn /= 6;
        graph.clear(); graph.resize(8 + m); n = graph.size();
        rem.clear(); rem.resize(8 + m, vi(8 + m, 0));
        for(int i = 2; i < 8; i++) {
            graph[s].push_back(i); graph[i].push_back(s);
            rem[s][i] = nn;
        }
        for(int i = 8; i < 8 + m; i++) {
            string a, b; cin >> a >> b;
            int aa = mp[a], bb = mp[b];
            graph[aa].push_back(i); graph[i].push_back(aa);
            rem[aa][i] = 1;
            graph[bb].push_back(i); graph[i].push_back(bb);
            rem[bb][i] = 1;
            graph[i].push_back(t); graph[t].push_back(i);
            rem[i][t] = 1;
        }
        int mx = maxFlow();
        if(mx == m) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}