//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n, m, c, q, start, des; cin >> n >> m;
    vi price(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    vvii graph(n);
    for(int i = 0; i < m; i++) {
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back(make_pair(b, d));
        graph[b].push_back(make_pair(a, d));
    }
    cin >> q;
    while(q--) {
        cin >> c >> start >> des;
        vvi dis(n, vi(c + 1, inf)); dis[start][0] = 0;
        priority_queue<iii, viii, greater<iii>> q; q.push(iii(0, ii(start, 0)));
        while(!q.empty()) {
            iii front = q.top(); q.pop();
            int fuel = front.second.second, d = front.first, station = front.second.first;
            if(station == des) break;
            if(dis[station][fuel] < d) continue;
            for(auto &e : graph[station]) {
                if(e.second > fuel) continue;
                if(d < dis[e.first][fuel - e.second]) {
                    dis[e.first][fuel - e.second] = d;
                    q.push(iii(d, ii(e.first, fuel - e.second)));
                }
            }
            if(fuel < c && d + price[station] < dis[station][fuel + 1]) {
                dis[station][fuel + 1] = d + price[station];
                q.push(iii(d + price[station], ii(station, fuel + 1)));
            }
        }
        int ans = inf;
        for(int i = 0; i <= c; i++) ans = min(ans, dis[des][i]);
        if(ans < inf) cout << ans << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}