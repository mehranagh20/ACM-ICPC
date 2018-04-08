//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9


vi dist, work;
int s, t, n; //fill s, t, n in main ---> s is start, t is destination and n is number of nodes in graph.
vvi rem, graph; //fill graph in main. graph is adjList. also fill rem where it keeps capacity of edjes in n * n space.
//it is possible to use rem to construct the path. if there was a path from i to j then rem[j][i] > 0
//if rem[j][i] = 0 before running Dinic's so it can change with questions...

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
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int tmp; cin >> tmp;
        vi a(tmp);
        for(int i = 0; i < tmp; i++) cin >> a[i];
        cin >> tmp;
        vi b(tmp);
        for(int i = 0; i < tmp; i++) cin >> b[i];
        graph.clear(); graph.resize(a.size() + b.size() + 2);
        s = a.size() + b.size(), t = a.size() + b.size() + 1;
        rem.clear(); rem.resize(t + 1, vi(t + 1, 0));
        for(int i = 0; i < a.size(); i++) {
            graph[s].push_back(i), graph[i].push_back(s), rem[s][i] = 1;
            for (int j = 0; j < b.size(); j++) {
                if(b[j] == 0 ||(a[i] && b[j] % a[i] == 0)) graph[i].push_back(a.size() + j), graph[a.size() + j].push_back(i), rem[i][a.size() + j] = 1;
            }
        }
        for(int i = a.size(); i < a.size() + b.size(); i++) graph[i].push_back(t), graph[t].push_back(i), rem[i][t] = 1;
        n = t + 1;
        cout << "Case " << i << ": " << maxFlow() << endl;
    }


    return 0;
}