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

vvii AdjList;
vvi graph;

void di(int s, int n, map<int, int> &mp) {
    vi dist(n, inf); dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // this is a very important check
        for (int j = 0; j < (int) AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    for(auto &e: mp) {
        if(dist[e.first] <= 600) graph[mp[s]].push_back(e.second);
    }
}

int bfs(map<int, int> &mp, int n) {
    vi dis(graph.size(), inf); dis[mp[0]] = 0;
    queue<int> q; q.push(mp[0]);
    while(q.size()) {
        int now = q.front(); q.pop();
        for(auto &e: graph[now]) if(dis[e] == inf) {
                dis[e] = dis[now] + 1;
                q.push(e);
            }
    }
    return dis[mp[n - 1]];
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        int h; cin >> h;
        map<int, int> mp;
        mp[0] = 0, mp[n - 1] = 1;
        for(int i = 0; i < h; i++) {
            int tmp; cin >> tmp;
            tmp--;
            mp[tmp] = i + 2;
        }
        graph.assign(h + 10, vi());
        AdjList.assign(n, vii());
        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            AdjList[a].push_back(ii(b, c));
            AdjList[b].push_back(ii(a, c));
        }
        for(auto e: mp)
            di(e.first, n, mp);
        int ans = bfs(mp, n);
        if(ans == inf) cout << -1 << endl;
        else cout << ans - 1 << endl;

    }


    return 0;
}
