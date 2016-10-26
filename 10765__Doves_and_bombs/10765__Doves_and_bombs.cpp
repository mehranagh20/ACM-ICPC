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

vvi graph;
vi dfs_num, dfs_low, parent;
int n, counter, root, rootChildren;
vii found;

void dfs(int s) {
    dfs_num[s] = dfs_low[s] = counter++;
    for(auto &e : graph[s]) {
        if(dfs_num[e] == inf) {
            parent[e] = s;
            if(s == root) rootChildren++;
            dfs(e);
            if(dfs_low[e] >= dfs_num[s])
                found[s].first++;
            dfs_low[s] = min(dfs_low[s], dfs_low[e]);
        }
        else if(e != parent[s])
            dfs_low[s] = min(dfs_low[s], dfs_num[e]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int m;
    while(cin >> n >> m && (n || m)) {
        graph.clear(); graph.resize(n);
        int a, b;
        while(cin >> a >> b && a != -1) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs_num.clear(); dfs_num.resize(n, inf);
        dfs_low.clear(); dfs_low.resize(n);
        parent.clear(); parent.resize(n);
        found.clear(); found.resize(n, make_pair(0, 0));
        for(int i = 0; i < n; i++) found[i].second = -i;

        counter = 0;
        for(int i = 0; i < n; i++) if(dfs_num[i] == inf) {
                found[i].first = -1; root = i;
                dfs(i);
            }
        sort(found.begin(), found.end());
        for(int i = n - 1; i >= n - m; i--) cout << -found[i].second << " " << found[i].first + 1 << endl;
        cout << endl;

    }

    return 0;
}