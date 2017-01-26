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

int main() {
    int m, ss, v;
    while(cin >> n >> m >> ss >> v) {
        s = n + m, t = n + m + 1;
        graph.clear(); graph.resize(t + 1);
        rem.clear(); rem.resize(t + 1, vi(t + 1, 0));
        int maxDis = ss * v;
        vdd coors(n);
        for(int i = 0; i < n; i++) {
            cin >> coors[i].first >> coors[i].second;
            graph[s].push_back(i); graph[i].push_back(s);
            rem[s][i] = 1;
        }
        for(int i = 0; i < m; i++) {
            double a, b; cin >> a >> b;
            for(int j = 0; j < coors.size(); j++) {
                dd e = coors[j];
                double dis = sqrt(pow(a - e.first, 2) + pow(b - e.second, 2));
                if(dis <= maxDis) {
                    graph[j].push_back(n + i); graph[n + i].push_back(j);
                    rem[j][n + i] = 1;
                }
            }
            graph[n + i].push_back(t); graph[t].push_back(n + i);
            rem[n + i][t] = 1;
        }
        int nn = n;
        n = graph.size();
        cout << nn - maxFlow() << endl;
    }

    return 0;
}