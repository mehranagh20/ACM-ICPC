//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

vi match, vis;

vi dist, work;
int s, t, n; //fill s, t, n in main ---> s is start, t is destination and n is number of nodes in graph.
vvii graph; //fill graph in main. graph is adjList. also fill rem where it keeps capacity of edjes in n * n space. edges must be bidictional ?
vvi where;
//it is possible to use rem to construct the path. if there was a path from i to j then rem[j][i] > 0
//if rem[j][i] = 0 before running Dinic's so it can change with questions...

bool dinic_bfs() {
    dist.clear(); dist.resize(n, -1); dist[s] = 0;
    queue<int> queue1; queue1.push(s);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int e = graph[u][i].first, ee = graph[u][i].second;
            if(dist[e] != -1 || ee <= 0) continue;
            dist[e] = dist[u] + 1;
            queue1.push(e);
        }
    }
    return (dist[t] != -1);
}

int dinic_dfs(int u, int f) {
    if(u == t) return f;
    for(int &i = work[u]; i < graph[u].size(); i++) {
        int v = graph[u][i].first, vv = graph[u][i].second;
        if(vv <= 0) continue;
        if(dist[u] + 1 == dist[v]) {
            int df = dinic_dfs(v, min(f, vv));
            if(df > 0) {
                graph[v][where[u][i]].second += df;
                graph[u][i].second -= df;
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
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int nn, ff, ss; cin >> nn >> ff >> ss;
        s = 0, t = ff + ss + 1, n = ff + ss + 2;
        vi a(ff + 1, 0), b(ss + 1, 0);
        for(int i = 0; i < nn; i++) {
            int tmp; cin >> tmp;
            a[tmp]++;
        }
        for(int i = 0; i < nn; i++) {
            int tmp; cin >> tmp;
            b[tmp]++;
        }
        vvi r(ff, vi(ss));
        for (int i = 0; i < ss; ++i) {
            for (int j = 0; j < ss; ++j) {
                cin >> r[i][j];
            }
        }
        graph.assign(n, vii());
        where.assign(n, vi());
        for(int i = 1; i <= ff; i++) {
            graph[i].push_back(ii(t, a[i]));
            where[i].push_back(graph[t].size());
            graph[t].push_back(ii(i, 0));
            where[t].push_back(graph[i].size() - 1);
        }
        for(int i = 1; i <= ss; i++) {
            graph[i + ff].push_back(ii(s, 0));
            where[i + ff].push_back(graph[s].size());
            graph[s].push_back(ii(i + ff, b[i]));
            where[s].push_back(graph[i + ff].size() - 1);
        }
        vvii graph2 = graph;
        vvi where2 = where;
        for(int i = 1; i <= ff; i++) for(int j = 1; j <= ss; j++) {
                if (r[i - 1][j - 1]) {
                    graph[i].push_back(ii(j + ff, 0));
                    where[i].push_back(graph[j + ff].size());
                    graph[j + ff].push_back(ii(i, inf));
                    where[j + ff].push_back(graph[i].size() - 1);
                }
                else {
                    graph2[i].push_back(ii(j + ff, 0));
                    where2[i].push_back(graph2[j + ff].size());
                    graph2[j + ff].push_back(ii(i, inf));
                    where2[j + ff].push_back(graph2[i].size() - 1);
                }
            }
        int sec = maxFlow();
        graph = graph2, where = where2;
        cout << nn - maxFlow() << " " << sec << endl;






    }
    return 0;
}
