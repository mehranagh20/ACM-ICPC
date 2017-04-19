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
    double m;
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        vii tmp(n);
        s = n * 2;
        graph.clear(); graph.resize(n * 2 + 1);
        rem.clear(); rem.resize(n * 2 + 1, vi(n * 2 + 1, 0));
        vii coor;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            int x, y, p, j; cin >> x >> y >> p >> j;
            tmp[i] = {p, j};
            tot += p;
            graph[i].push_back(i + n); graph[i + n].push_back(i);
            rem[i][i + n] = j;
            if(p) {
                graph[s].push_back(i); graph[i].push_back(s);
                rem[s][i] = p;
            }
            for(int j = 0; j < coor.size(); j++) {
                int xx = coor[j].first, yy = coor[j].second;
                double dis = sqrt(pow(xx - x, 2) + pow(yy - y, 2));
                if(dis <= m) {
                    graph[i + n].push_back(j); graph[j].push_back(i + n);
                    graph[j + n].push_back(i); graph[i].push_back(j + n);
                    rem[i + n][j] = rem[j + n][i] = inf;
                }
            }
            coor.push_back(ii(x, y));
        }
        //cout << tot << endl;
       // vvi tmp = rem;
        int nn = n;
        n = graph.size();
        vi ans;
        for(int i = 0; i < nn; i++) {
            t = i;
            //rem = tmp;
            for(int i = 0; i < nn; i++) {
                rem[s][i] = tmp[i].first;
                rem[i][i + nn] = tmp[i].second;
                rem[i + nn][i] = 0; rem[i][s] = 0;
            }
            if(maxFlow() == tot) ans.push_back(i);
        }
        if(ans.size()) {
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
            cout << endl;
        }
        else cout << -1 << endl;
    }


    return 0;
}