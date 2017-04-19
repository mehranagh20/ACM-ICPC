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
int n, counter, root;
vii ans;

void dfs(int s) {
    dfs_num[s] = dfs_low[s] = counter++;
    for(auto &e : graph[s]) {
        if(dfs_num[e] == inf) {
            parent[e] = s;

            dfs(e);

            if(dfs_low[e] > dfs_num[s])
                e > s ? ans.push_back(make_pair(s, e)) : ans.push_back(make_pair(e, s));
            dfs_low[s] = min(dfs_low[s], dfs_low[e]);
        }
        else if(e != parent[s])
            dfs_low[s] = min(dfs_low[s], dfs_num[e]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n) {
        graph.clear(); graph.resize(n);
        for(int i = 0; i < n; i++) {
            int a, b, c; cin >> a;
            char tmp; cin >> tmp >> b >> tmp;
            for(int i = 0; i < b; i++) {
                cin >> c;
                graph[c].push_back(a);
                graph[a].push_back(c);
            }
        }
        dfs_num.clear(); dfs_num.resize(n, inf);
        dfs_low.clear(); dfs_low.resize(n);
        parent.clear(); parent.resize(n);

        counter = 0;
        ans.clear();
        for(int i = 0; i < n; i++) if(dfs_num[i] == inf) dfs(i);
        sort(ans.begin(), ans.end());
        cout << ans.size() << " critical links\n";
        for(auto &e : ans) cout << e.first << " - " << e.second << endl;
        cout << endl;
    }

    return 0;
}