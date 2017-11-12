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

vii blue, red;
int d;
vvi dis;

int s, t, f, mf; //s is start node, t is destination, fill s and t in main. mf will hold the max flow.
vvi graph, res;//graph is adjList fill it in main, res is a n * n 2D vec with capacity of each edge.
vi p;

void augment(int v, int minEdge) {
    if(v == s) {
        f = minEdge; return;
    }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

void edmonsKarp(int n) { // n is the graph size. answer is in mf after calling this method.
    mf = 0;
    while(1) {
        f = 0;
        vector<bool> vis(n, false); vis[s] = true;
        p.clear(); p.resize(n, -1);
        queue<int> queue1; queue1.push(s);
        while(!queue1.empty()) {
            int u = queue1.front(); queue1.pop();
            if(u == t) break;
            for(auto &e : graph[u]) {
                if(res[u][e] > 0 && !vis[e]) vis[e] = true, queue1.push(e), p[e] = u;
            }
        }
        augment(t, inf);
        if(f == 0) break;
        mf += f;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        blue.clear(); red.clear();
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) {
            string s;
            int a, b; cin >> a >> b >> s;
            if(s == "blue") blue.push_back(ii(a, b));
            else red.push_back(ii(a, b));
        }
        dis.assign(blue.size(), vi(red.size()));
        for(int i = 0; i < blue.size(); i++) for(int j = 0; j < red.size(); j++)
            dis[i][j] = pow(blue[i].first - red[j].first, 2) + pow(blue[i].second - red[j].second, 2);

        int l = 0, h = 5000, ans = inf;
        while(l <= h) {
            int r = (l + h) / 2;
            d = r * r;

            graph.assign(n + 2, vi());
            res.assign(graph.size(), vi(graph.size(), 0));
            for(int i = 0; i < blue.size(); i++)
                graph[0].push_back(i + 1), graph[i + 1].push_back(0), res[0][i + 1] = 1;
            for(int i = 0; i < red.size(); i++)
                graph[blue.size() + 1 + i].push_back(n + 1), graph[n + 1].push_back(blue.size() + 1 + i), res[blue.size() + 1 + i][n + 1] = 1;
            for(int i = 0; i < blue.size(); i++) for(int j = 0; j < red.size(); j++) if(dis[i][j] <= d)
                graph[i + 1].push_back(j + 1 + blue.size()), graph[j + 1 + blue.size()].push_back(i + 1), res[i + 1][j + 1 + blue.size()] = 1;
            s = 0, t = n + 1;
            edmonsKarp(graph.size());

            if(mf >= k) h = r - 1, ans = min(ans, r);
            else l = r + 1;
        }
        if(ans == inf) cout << "Impossible\n";
        else cout << ans << endl;
    }


    return 0;
}
