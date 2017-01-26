//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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

int main() {
    int q, c;
    s = 0, t = 1; // 2 to c is Cat nodes, c + 1 to q ins question nodes.
    while(cin >> c >> q && (q || c)) {
        int tot = 0;
        n = q + c + 2;
        graph.clear(); graph.resize(n);
        rem.clear(); rem.resize(n, vi(n, 0));
        for(int i = 2 + c; i < 2 + c + q; i++) {
            graph[s].push_back(i); graph[i].push_back(s);
            rem[s][i] = 1;
        }
        for(int i = 2; i < 2 + c; i++) {
            int cc; cin >> cc;
            tot += cc;
            graph[i].push_back(t); graph[t].push_back(i);
            rem[i][t] = cc;
        }
        for(int i = 2 + c; i < q + 2 + c; i++) {
            int qq; cin >> qq;
            for(int j = 0; j < qq; j++) {
                int cc; cin >> cc; cc += 2;
                graph[i].push_back(cc - 1); graph[cc - 1].push_back(i);
                rem[i][cc - 1] = 1;
            }
        }
        int mx = maxFlow();
        if(mx == tot) {
            cout << 1 << endl;
            for(int i = 2; i < c + 2; i++) {
                vi ans;
                for(int j = c + 2; j < c + 2 + q; j++) if(rem[i][j] > 0) ans.push_back(j - c - 2 + 1);
                if(ans.size()) cout << ans[0];
                for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
                cout << endl;
            }
        }
        else cout << 0 << endl;
    }

    return 0;
}