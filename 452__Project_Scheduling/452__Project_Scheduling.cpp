//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

//void topSort(vi &order, int n, vi &vis, vvi &graph) {
//    vis[n] = 1;
//    for(auto &e : graph[n]) if(!vis[e]) topSort(order, e, vis, graph);
//    order.push_back(n);
//}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    cin.get(); cin.get();
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        vvi graph; graph.resize(26);
        vi weight(26, 0), incomingEd(26, -1);
        string str;
        while(getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            str = "";
            char name; int days; ss >> name >> days >> str;
            if(incomingEd[name - 65] == -1) incomingEd[name - 65] = 0;
            for(auto &e : str) {
                graph[name - 65].push_back(e - 65);
                incomingEd[e - 65]++;
            }
            weight[name - 65] = days;
        }
        queue<int> queue1;
        vi dis(26, -inf);
        int ans = -inf;
        for(int i = 0; i < 26; i++) if(!incomingEd[i])
                queue1.push(i), dis[i] = weight[i], ans = max(ans, weight[i]);
        while(!queue1.empty()) {
            int p = queue1.front(); queue1.pop();
            for(auto &e : graph[p]) {
                if(dis[p] + weight[e] <= dis[e]) continue;
                dis[e] = dis[p] + weight[e];
                ans = max(ans, dis[e]);
                queue1.push(e);
            }
        }
        cout << ans << endl;

    }

    return 0;
}