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

vvii graph;
void dfs(int &n, int i, vi &vis) {
    vis[i] = 1;
    for(auto &e: graph[i]) if(!vis[e.first]) {
            n++;
            dfs(n, e.first, vis);
        }
    vis[i] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    graph.assign(n + 1, vii());
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(ii(b, 0));
        graph[b].push_back(ii(a, 0));
    }
    vi vis(n + 1, 0);
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            int k = 0;
            vis[i] = 1;
            dfs(k, graph[i][j].first, vis);
            vis[i] = 0;
            graph[i][j].second = k + 1;
        }
    }
    int mx = -1, z = -1;
    for(int i = 0; i < n + 1; i++) {
        int sum = 0;
        for(auto &e: graph[i]) sum += e.second;
        int cur = 0;
        for(auto &e: graph[i]) cur += (sum - e.second) * e.second;
        cur /= 2;
        if(cur > mx) {z = i; mx = cur;};
    }
    vi tmp;
    for(auto &e: graph[z]) tmp.push_back(e.second);
    sort(tmp.begin(), tmp.end());
    int cur = 0;
    for(int i = 0; i < 2 && tmp.size(); i++) {
        cur += tmp.back();
        for(auto &e: graph[z]) if(e.second == tmp.back()) {
                e.second = 0;
                break;
            }
        tmp.pop_back();
    }
    int ans = 0;
    int sum = 0;
    graph[z].push_back(ii(0, cur));
    for(auto &e: graph[z]) sum += e.second;
    for(auto &e: graph[z]) ans += (sum - e.second) * e.second;
    cout << mx << " " << ans / 2 << endl;

    return 0;
}
