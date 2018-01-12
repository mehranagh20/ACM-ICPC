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

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
vvi graph;
multiset<ii> st;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)graph[u].size(); j++) {
        int v = graph[u][j];
        if(st.find(ii(u, v)) != st.end()) continue;
        if (dfs_num[v] == 0)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
//        printf("SCC %d:", ++numSCC);
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
//            printf(" %d", v);
            if (u == v) break; }
//        printf("\n");
    } }


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        st.clear();
        dfs_num.assign(n, 0); dfs_low.assign(n, 0); visited.assign(n, 0);
        graph.assign(n, vi());
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
        }
        int num = m;
        for(int i = 0; i < n; i++) for(auto &e: graph[i]) {
                if(num <= 2 * n) break;
                auto it = st.insert(ii(i, e));
                dfsNumberCounter = numSCC = 0;
                fill(dfs_num.begin(), dfs_num.end(), 0);
                fill(dfs_low.begin(), dfs_low.end(), 0);
                fill(visited.begin(), visited.end(), 0);
                int x = 0;
                for (int i = 0; i < n; i++)
                    if (dfs_num[i] == 0) {
                        tarjanSCC(i);
                        x++;
                        if(x > 1) break;
                    }
                if(x > 1) st.erase(it);
                else {
                    cout << i + 1 << ' ' << e + 1 << endl;
                    num--;
                }
            }
    }


    return 0;
}
