//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vi graph, memo;
vector<bool> vis;

int dfs(int s) {
    vis[s] = true;
    int tmp = 0;
    if(!vis[graph[s]]) tmp += 1 + dfs(graph[s]);
    else tmp = 1;
    vis[s] = false;
    return memo[s] = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n; cin >> n;
        graph.clear(); graph.resize(n);
        while (n--) {
            int a, b; cin >> a >> b;
            graph[a - 1] = b - 1;
        }
        vis.clear(); vis.resize(graph.size() + 5, false);
        memo.clear(); memo.resize(graph.size() + 5, 0);
        int ans = 0, depth = 1, rAns;
        for (int i = 0; i < graph.size(); i++) {
            int tmp = memo[i];
            if(!memo[i]) tmp = dfs(i);
            if(tmp > ans) {
                ans = tmp; rAns = i;
            }
        }
        cout << "Case " << i << ": " << rAns + 1 << endl;
    }

    return 0;
}