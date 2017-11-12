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

vvi graph;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
map<int, int> mp;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)graph[u].size(); j++) {
        int v = graph[u][j];
        if (dfs_num[v] == 0)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        numSCC++;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            mp[v] = numSCC;
            if (u == v) break; }
    } }


int main() {
    ios::sync_with_stdio(0);

    int n, r, l; cin >> n >> r >> l;
    vii lamps(l);
    for(auto &e: lamps) cin >> e.first >> e.second;

    graph.assign(2 * l, vi());
    for(int i = 0; i < l; i++) {
        for(int j = i + 1; j < l; j++) {
            if(lamps[i].first == lamps[j].first) {
                if(abs(lamps[i].second - lamps[j].second) <= 2 * r) {
                    graph[i].push_back(j + l);
                    graph[j].push_back(i + l);
                }
            }
            else if(lamps[i].second == lamps[j].second) {
                if(abs(lamps[i].first - lamps[j].first) <= 2 * r) {
                    graph[i + l].push_back(j);
                    graph[j + l].push_back(i);
                }
            }
        }
    }

    dfs_num.assign(l * 2, 0); dfs_low.assign(l * 2, 0); visited.assign(l * 2, 0);
    dfsNumberCounter = numSCC = 0;
    for (int i = 0; i < 2 * l; i++)
        if (dfs_num[i] == 0)
            tarjanSCC(i);


    bool ok = true;
    for(int i = 0; i < l; i++) {
        if(mp[i] == mp[i + l])
            ok = false;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;



    return 0;
}
