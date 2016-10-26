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
vi dfs_num, dfs_low, scc, vis;
vector<string> numToString;
int n, counter, m;

void dfs(int s) {
    dfs_num[s] = dfs_low[s] = counter++;
    scc.push_back(s);
    vis[s] = 1;
    for(auto &e : graph[s]) {
        if(dfs_num[e] == inf) dfs(e);
        if(vis[e]) dfs_low[s] = min(dfs_low[s], dfs_low[e]);
    }
    if(dfs_low[s] == dfs_num[s]) {
        while (true) {
            int tmp = scc.back(); scc.pop_back(); vis[tmp] = 0;
            cout << numToString[tmp];
            if (tmp != s) cout << ", ";
            else break;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tc = 0;
    while(cin >> n >> m && (n || m)) {
        if(tc++) cout << endl;
        cout << "Calling circles for data set " << tc << ":\n";
        int ind = 0;
        map<string, int> mp;
        set<pair<string, string>> sameCall;
        numToString.clear();
        graph.clear(); graph.resize(n);
        for(int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            if(mp.find(a) == mp.end()) {
                mp[a] = ind++; numToString.push_back(a);
            }
            if(mp.find(b) == mp.end()) {
                mp[b] = ind++; numToString.push_back(b);
            }
            graph[mp[a]].push_back(mp[b]);
        }
        dfs_num.clear(); dfs_num.resize(n, inf);
        dfs_low.clear(); dfs_low.resize(n);
        vis.clear(); vis.resize(n, 0);
        scc.clear();
        counter = 0;
        for(int i = 0; i < n; i++)
            if(dfs_num[i] == inf)
                dfs(i);
    }

    return 0;
}