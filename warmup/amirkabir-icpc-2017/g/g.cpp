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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9


vvi graph;
vi bfs(int n, int s) {
    vi dist(n, inf); dist[s] = 0; // distance from source s to s is 0
    queue<int> q; q.push(s);
    vi p(n); p[s] = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int) graph[u].size(); j++) {
            int v = graph[u][j];
            if (dist[v] == inf) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    return p;
}

void dfs(int &n, int i, vi &vis) {
    vis[i] = 1;
    for(auto &e: graph[i]) if(!vis[e]) {
            n++;
            dfs(n, e, vis);
        }
}

int main() {
    ios::sync_with_stdio(0);
    int n, r, b; cin >> n >> r >> b;
    graph.assign(n, vi());
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi par = bfs(n, r);
    vi seq;
    int i = b, j;
    while(i != par[i]) {
        seq.push_back(i);
        i = par[i];
    }
    vi real = {r};
    for(int i = seq.size() - 1; i >= 0; i--) real.push_back(seq[i]);

    i = 0, j = real.size() - 1;
    int nn = 0, mm = 0;
    while(1) {
        if(i > j) break;
        int col = -1;
        if(i == j) col = 0;
        if(col == -1) {
            i++;
            if (i == j) col = 1;
            if (col == -1) {
                j--;
                if (i == j) col = 0;
            }
        }
        if(col != -1) {
            vi all, vis(n, 0);
            vis[real[i]] = 1;
            for(auto &e: graph[real[i]]) {
                int s = 1;
                dfs(s, e, vis);
                if(i && e == real[i - 1]) nn += s;
                else if(j != real.size() - 1 && e == real[j + 1]) mm += s;
                else all.push_back(s);
            }
            sort(all.begin(), all.end());
            for(int i = all.size() - 1; i >= 0; i--) {
                if(col) mm += all[i];
                else nn += all[i];
                col = (col ? 0 : 1);
            }
            break;
        }
    }
    cout << nn << " " << mm << endl;

    return 0;
}

