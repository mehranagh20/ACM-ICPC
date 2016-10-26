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
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, m, s, t; cin >> n >> m >> s >> t;
        vvii graph(n);
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back(ii(b, c));
            graph[b].push_back(ii(a, c));
        }
        vi dis(n, inf); dis[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> queue1; queue1.push(ii(0, s));
        while(!queue1.empty()) {
            int n = queue1.top().second, d = queue1.top().first;
            queue1.pop();
            if(dis[n] < d) continue;
            for(auto &e : graph[n]) {
                if(dis[e.first] > d + e.second) {
                    dis[e.first] = d + e.second;
                    queue1.push(ii(dis[e.first], e.first));
                }
            }
        }
        cout << "Case #" << i << ": ";
        if(dis[t] == inf) cout << "unreachable\n";
        else cout << dis[t] << endl;
    }

    return 0;
}