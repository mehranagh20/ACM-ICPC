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
vi dfs_num, dfs_low, parent, found;
int n, ans, counter, root, rootChildren;

void dfs(int s) {
    dfs_num[s] = dfs_low[s] = counter++;
    for(auto &e : graph[s]) {
        if(dfs_num[e] == inf) {
            parent[e] = s;
            if(s == root) rootChildren++;
            dfs(e);
            if(dfs_low[e] >= dfs_num[s])
                if(!found[s]) {
                    found[s] = 1;
                    ans++;
                }
            dfs_low[s] = min(dfs_low[s], dfs_low[e]);
        }
        else if(e != parent[s])
            dfs_low[s] = min(dfs_low[s], dfs_num[e]);
    }
}

int main() {
    //ios::sync_with_stdio(0);
    while(cin >> n && n) {
        graph.clear(); graph.resize(n);
        dfs_num.clear(); dfs_num.resize(n, inf);
        dfs_low.clear(); dfs_low.reserve(n);
        parent.clear(); parent.resize(n);
        found.clear(); found.resize(n, 0);
        cin.get();
        string str;
        while(getline(cin, str)) {
            int a, b;
            stringstream s(str); s >> a;
            if(!a) break;
            while(s >> b) {
                graph[a - 1].push_back(b - 1);
                graph[b - 1].push_back(a - 1);
            }
        }
        ans = counter = 0;
        for(int i = 0; i < n; i++)
            if(dfs_num[i] == inf) {
                root = i; rootChildren = 0;
                dfs(i);
                if(rootChildren > 1) ans++;
            }
        cout << ans - 1 << endl;
    }

    return 0;
}