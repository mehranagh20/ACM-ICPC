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

int mx, node, n;
vi vis;
vviii graph;

void dfs(int i, int d) {
    vis[i] = 1;
    if(mx < d) mx = d, node = i;
    for(auto &e : graph[i]) if(!vis[e.first] && e.second.first) {
            dfs(e.first, d + 1);
        }
}

void bfs(int i, int j, vi &par) {
    vi dis(n, inf); dis[i] = 0, par[i] = i;
    queue<int> queue1; queue1.push(i);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        if(u == j) return;
        for(auto &e : graph[u]) if(dis[e.first] == inf && e.second.first)
                dis[e.first] = dis[u] + 1, par[e.first] = u, queue1.push(e.first);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> n;
        graph.clear(); graph.resize(abs(n));
        for(int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            graph[a].push_back(iii(b, ii(1, graph[b].size()))); graph[b].push_back(iii(a, ii(1, graph[a].size() - 1)));
        }

        //constructing diameter of graph.
        vis.clear(); vis.resize(n, 0), mx = -inf; dfs(0, 0);
        int f = node;
        vis.clear(); vis.resize(n, 0), mx = -inf; dfs(node, 0);
        vi par(n), seq = {f};
        bfs(node, f, par);
        while(par[seq.back()] != seq.back()) seq.push_back(par[seq.back()]);

        //try all possible edges to remove and connect centers of two new longest paths.
        ii delAns = {0, 1}, consAns = {0, 1};
        int tmpMx = mx;
        for(int i = 0; i < seq.size() - 1; i++) {
            vi s(n), ff, ss;
            int fr = seq[i], sr = seq[i + 1];

            for(auto &e : graph[fr]) if(e.first == sr) {
                    e.second.first = graph[sr][e.second.second].second.first = 0;
                    break;
                }

            vis.clear(); vis.resize(n, 0), mx = -inf; dfs(fr, 0);
            int tmp = node;
            vis.clear(); vis.resize(n, 0), mx = -inf; dfs(node, 0);
            bfs(tmp, node, s);
            ff= {node};
            while(s[ff.back()] != ff.back()) ff.push_back(s[ff.back()]);

            vis.clear(); vis.resize(n, 0), mx = -inf; dfs(sr, 0);
            tmp = node;
            vis.clear(); vis.resize(n, 0), mx = -inf; dfs(node, 0);
            bfs(tmp, node, s);
            ss = {node};
            while(s[ss.back()] != ss.back()) ss.push_back(s[ss.back()]);

            int fc = ff[ff.size() / 2], sc = ss[ss.size() / 2];
            graph[fc].push_back(iii(sc, ii(1, graph[sc].size()))); graph[sc].push_back(iii(fc, ii(1, graph[fc].size() - 1)));
            vis.clear(), vis.resize(n, 0), mx = -inf; dfs(fr, 0);
            vis.clear(), vis.resize(n, 0), mx = -inf; dfs(node, 0);
            if(mx < tmpMx) {
                tmpMx = mx, delAns = {fr, sr}, consAns = {fc, sc};
            }
            graph[fc].pop_back(), graph[sc].pop_back();
            for(auto &e : graph[fr]) if(e.first == sr) {
                    e.second.first = graph[sr][e.second.second].second.first = 1;
                    break;
                }
        }
        cout << tmpMx << endl;
        cout << delAns.first + 1 << " " << delAns.second + 1 << endl;
        cout << consAns.first + 1 << " " << consAns.second + 1 << endl;


    }
    return 0;
}