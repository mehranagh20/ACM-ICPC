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
vvii memo;
int n, m;

vi vis;
int dfs(int n) {
    vis[n] = 1;
    for(auto &e: graph[n]) if(!vis[e]) dfs(e);
}

int root;

ii solve(int id, int used, int p) {
    ii &now = memo[id][used];
    if(now != ii(-1, -1)) return now;
    if(!used) {
        int a = 0, b = 0;
        for(auto &e: graph[id]) {
            if(e == p) continue;
            ii tmp = solve(e, 1, id);
            a += tmp.first, b += tmp.second;
        }
        return now = ii(a + 1, b);
    }
    ii ff = ii(0, 0), ss = ii(0, 0);
    for(auto &e: graph[id]) {
        if(e == p) continue;
        ii tmp1 = solve(e, 1, id);
        ii tmp2 = solve(e, 0, id);
        ff.first += tmp1.first, ff.second += tmp1.second;
        ss.first += tmp2.first, ss.second += tmp2.second;
    }
    ff.first += 1, ff.second += (id != root);
    if(ff.first < ss.first) now = ff;
    else if(ff.first > ss.first) now = ss;
    else if(ff.second > ss.second) now = ff;
    else now = ss;
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        graph.assign(n + 10, vi());
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b), graph[b].push_back(a);
        }
        memo.assign(n + 10, vii(2, ii(-1, -1)));
        ii ans = ii(0, 0);
        vis.assign(n, 0);
        for(int i= 0; i < n; i++) {
            if(!vis[i]) {
                root = i;
                dfs(i);
                ii tmp = solve(i, 1, -1);
                ans.first += tmp.first, ans.second += tmp.second;
            }
        }
        cout << ans.first << " " << ans.second << " " << m - ans.second << endl;

    }

    return 0;
}
