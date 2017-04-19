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
   vvi mp(210, vi(210, 0));
    mp['.']['.'] = mp['.']['@'] = mp['.']['#'] = 1;
    mp['*']['.'] = mp['*']['@'] = mp['*']['#'] = 1;
    mp['@']['@'] = mp['@']['#'] = inf; mp['@']['.'] = 1;
    mp['#']['#'] = inf; mp['#']['@'] = inf; mp['#']['.'] = 1;
    int x, y, p;
    while(cin >> x >> y >> p) {
        int ind = 0;
        vector<vector<char>> grid(x + 1, vector<char>(y + 1));
        vvi ids(x + 1, vi(y + 1, -1));
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) {
                cin >> grid[i][j];
                if(grid[i][j] != '~') ids[i][j] = ind++;
                if(grid[i][j] == '.') ind++;
            }
        s = ind, t = ind + 1;
        graph.clear(); graph.resize(ind + 2);
        rem.clear(); rem.resize(ind + 2, vi(ind + 2, 0));
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) {
                if(grid[i][j] == '*') {
                    graph[s].push_back(ids[i][j]); graph[ids[i][j]].push_back(s);
                    rem[s][ids[i][j]] = 1;
                }
                if(grid[i][j] == '#') {
                    graph[ids[i][j]].push_back(t); graph[t].push_back(ids[i][j]);
                    rem[ids[i][j]][t] = p;
                }
                if(grid[i][j] == '.') {
                    int a = ids[i][j];
                    graph[a].push_back(a + 1); graph[a + 1].push_back(a);
                    rem[a][a + 1] = 1;
                }
            }
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) {
                int a = grid[i][j], b = grid[i + 1][j], c = grid[i][j + 1], idAI = ids[i][j], idBI = ids[i + 1][j], idCI = ids[i][j + 1];
                int idAO = idAI, idBO = idBI, idCO = idCI;
                if(grid[i][j + 1] == '.') idCO = idCI + 1;
                if(grid[i][j] == '.') idAO = idAI + 1;
                if(grid[i + 1][j] == '.') idBO = idBI + 1;
                if(mp[a][b]) {
                    graph[idAO].push_back(idBI); graph[idBI].push_back(idAO);
                    rem[idAO][idBI] = mp[a][b];
                }
                if(mp[b][a]) {
                    graph[idAI].push_back(idBO); graph[idBO].push_back(idAI);
                    rem[idBO][idAI] = mp[b][a];
                }
                if(mp[a][c]) {
                    graph[idAO].push_back(idCI); graph[idCI].push_back(idAO);
                    rem[idAO][idCI] = mp[a][c];
                }
                if(mp[c][a]) {
                    graph[idAI].push_back(idCO); graph[idCO].push_back(idAI);
                    rem[idCO][idAI] = mp[c][a];
                }
            }
        n = graph.size();
        cout << maxFlow() << endl;
    }

    return 0;
}