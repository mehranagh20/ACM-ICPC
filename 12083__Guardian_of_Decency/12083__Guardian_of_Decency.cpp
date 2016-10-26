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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9
int s, t, n;
vvi graph, rem;
vi dist, work;

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
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int nn; cin >> nn;
        s = nn, t = nn + 1;
        vi height;
        vector<char> sex;
        vector<string> mus, spo;
        rem.clear(); rem.resize(nn + 2, vi(nn + 2, 0));
        graph.clear(); graph.resize(nn + 2);
        for(int i = 0; i < nn; i++) {
            int h;
            char se;
            string music, sport;
            cin >> h >> se >> music >> sport;
            se == 'M' ? (graph[s].push_back(i), graph[i].push_back(s), rem[s][i] = 1) : (graph[i].push_back(t), graph[t].push_back(i), rem[i][t] = 1);
            for(int j = 0; j < i; j++) {
                if(abs(height[j] - h) <= 40 && sex[j] != se && spo[j] != sport && mus[j] == music) {
                    graph[i].push_back(j), graph[j].push_back(i);
                    se == 'M' ? rem[i][j] = 1 : rem[j][i] = 1;
                }
            }
            height.push_back(h), sex.push_back(se), mus.push_back(music), spo.push_back(sport);
        }
        n = nn + 2;
        cout << nn - maxFlow() << endl;
    }

    return 0;
}