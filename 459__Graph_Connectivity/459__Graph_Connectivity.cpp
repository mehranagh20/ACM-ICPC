#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vvi adjList;
vi vis;

void dfs(int v) {
    vis[v] = 1;
    for(auto &e : adjList[v])
        if(!vis[e]) dfs(e);
}

int main() {
    ios::sync_with_stdio(0);
    int tc, blank = 0; cin >> tc;
    while(tc--) {
        if(blank++) cout << endl;
        int ans = 0;
        char mx; cin >> mx;
        adjList.clear(); adjList.resize(mx - 64);
        string s; cin.get();
        while(getline(cin, s) && !s.empty()) {
            adjList[s[0] - 65].push_back(s[1] - 65);
            adjList[s[1] - 65].push_back(s[0] - 65);
        }
        vis.clear(); vis.resize(mx - 64, 0);
        for(int i = 0; i <= mx - 65; i++) if(!vis[i]) {
                ans++;
                dfs(i);
            }
        cout << ans << endl;
    }

    return 0;
}