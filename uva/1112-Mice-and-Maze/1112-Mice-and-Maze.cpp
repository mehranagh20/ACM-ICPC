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
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        int n, s, t, m; cin >> n >> s >> t >> m;
        s--;
        vvii graph(n);
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            graph[b - 1].push_back(ii(a - 1, c));
        }
        vi dis(n, inf), consBef(n, 0); dis[s] = 0;
        int ans = 0;
        priority_queue<ii, vii, greater<ii>> queue1; queue1.push(ii(0, s));
        while(!queue1.empty()) {
            ii front = queue1.top(); queue1.pop();
            int n = front.second, d = front.first;
            if(!consBef[n] && d <= t) {
                ans++;
                consBef[n] = 1;
            }
            if(dis[n] < d) continue;
            for(auto &e : graph[n]) {
                if(dis[e.first] > d + e.second) {
                    dis[e.first] = d + e.second;
                    if(dis[e.first] <= t) queue1.push(ii(dis[e.first], e.first));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}