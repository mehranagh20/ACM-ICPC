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
    int nn, tc = 0;
    s = 0, t = 1;
    while(cin >> nn) {
        tc++;
        graph.clear(); graph.resize(2 + nn * 2);
        rem.clear(); rem.resize(2 + nn * 2, vi(2 + nn * 2, 0));
        int ind = 2;
        vi regIn(nn);
        for(int i = 0; i < nn; i++) {
            int c; cin >> c;
            regIn[i] = ind++;
            graph[ind - 1].push_back(ind); graph[ind].push_back(ind - 1);
            rem[ind - 1][ind] = c; ind++;
        }
        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            int fId = regIn[a], sId = regIn[b];
            graph[fId + 1].push_back(sId); graph[sId].push_back(fId + 1);
            rem[fId + 1][sId] = c;
        }
        int b, d; cin >> b >> d;
        for(int i = 0; i < b; i++) {
            int a; cin >> a; a--;
            graph[s].push_back(regIn[a]); graph[regIn[a]].push_back(s);
            rem[s][regIn[a]] = inf;
        }
        for(int i = 0; i < d; i++) {
            int a; cin >> a; a--;
            graph[regIn[a] + 1].push_back(t); graph[t].push_back(regIn[a] + 1);
            rem[regIn[a] + 1][t] = inf;
        }
        n = graph.size();
        int mf = maxFlow();
        cout << mf << endl;


    }

    return 0;
}