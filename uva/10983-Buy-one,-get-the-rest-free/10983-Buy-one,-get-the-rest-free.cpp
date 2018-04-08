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
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

//Dinic network max flow algorithm, runs in O(V^2*E) time.
//efficient for graph with lots of edges.

vi dist, work;
int s, t, n, cost; //fill s, t, n in main ---> s is start, t is destination and n is number of nodes in graph.
vvi rem;
vvii graph;

bool dinic_bfs() {
    dist.clear(); dist.resize(n, -1); dist[s] = 0;
    queue<int> queue1; queue1.push(s);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        for(auto &e : graph[u]) {
            if(dist[e.first] != -1 || rem[u][e.first] <= 0 || e.second > cost) continue;
            dist[e.first] = dist[u] + 1;
            queue1.push(e.first);
        }
    }
    return (dist[t] != -1);
}

int dinic_dfs(int u, int f) {
    if(u == t) return f;
    for(int &i = work[u]; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if(rem[u][v] <= 0 || graph[u][i].second > cost) continue;
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
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        int d, m; cin >> n >> d >> m;
        vi costs(m);
        d++;
        s = n * d, t = n * d - 1;
        graph.clear(); graph.resize(n * d + 1);
        vvi rrem(n * d + 1, vi(n * d + 1, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < d - 1; j++) {
                graph[i * d + j].push_back(ii(i * d + j + 1, -1)), graph[i * d + j + 1].push_back(ii(i * d + j, -1));
                rrem[i * d + j][i * d + j + 1] = inf;
            }
        for(int i = 0; i < m; i++) {
            int u, v, c, p, e; cin >> u >> v >> c >> p >> e;
            costs[i] = p;
            u--, v--;
            graph[u * d + e].push_back(ii(v * d + e + 1, p)), graph[v * d + e + 1].push_back(ii(u * d + e, p));
            rrem[u * d + e][v * d + e + 1] = c;
        }
        int allOfPass = 0;
        for(int i = 0; i < n; i++) {
            int tmp;
            graph[s].push_back(ii(i * d, -1)), graph[i * d].push_back(ii(s, -1));
            cin >> tmp;
            rrem[s][i * d] = tmp;
            allOfPass += tmp;
        }
        int a = 0, b = costs.size(), ans = -1;
        n = graph.size();
        sort(costs.begin(), costs.end());
        while(a <= b) {
            int mid = (a + b) / 2;
            rem = rrem, cost = costs[mid];
            int c = maxFlow();
            if(c == allOfPass) ans = costs[mid], b = mid - 1;
            else a = mid + 1;
        }
//        for(int i = 0; i < costs.size(); i++) {
//            cost = costs[i];
//            rem = rrem;
//            cerr << i << " " << maxFlow() << endl;
//        }
        cout << "Case #" << i + 1 << ": ";
        if(ans == -1) cout << "Impossible\n";
        else cout << ans << endl;

    }
}