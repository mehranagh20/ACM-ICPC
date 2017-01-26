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
    int n, k;
    while(cin >> n >> k) {
        vvi tmpGraph(100, vi(100, inf));
        vvii graph(100);
        vi cost(n); for(int i = 0; i < n; i++) cin >> cost[i];
        cin.get(); string s;
        for(int k = 0; k < n; k++) {
            getline(cin, s);
            stringstream ss(s);
            vi tmp;
            int t;
            while(ss >> t) tmp.push_back(t);
            for(int i = 0; i < tmp.size(); i++) for(int j = 0; j < tmp.size(); j++) {
                    if(i == j) continue;
                    tmpGraph[tmp[i]][tmp[j]] = min(tmpGraph[tmp[i]][tmp[j]], abs(tmp[i] - tmp[j]) * cost[k]);
                }
        }
        for(int i = 0; i < 100; i++) for(int j = i + 1; j < 100; j++)
                if(tmpGraph[i][j] != inf) {
                    graph[i].push_back(ii(j, tmpGraph[i][j]));
                    graph[j].push_back(ii(i, tmpGraph[i][j]));
                }
        vi dis(100, inf); dis[0] = 0;
        int ans = inf;
        priority_queue<ii, vii, greater<ii>> queue1; queue1.push(ii(0, 0));
        while(!queue1.empty()) {
            int n = queue1.top().second, d = queue1.top().first;
            if(n == k) {
                ans = dis[n];
                break;
            }
            queue1.pop();
            if(dis[n] < d) continue;
            for(auto &e : graph[n]) {
                if(dis[e.first] > e.second + dis[n] + (n == 0 ? 0 : 60)) {
                    dis[e.first] = e.second + dis[n] + (n == 0 ? 0 : 60);
                    queue1.push(ii(dis[e.first], e.first));
                }
            }
        }
        if(ans == inf) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;
    }

    return 0;
}