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
#define pi acos(-1)

vvi graph;
vi vis;

void dfs(int u){
    vis[u] = 1;
    for(auto v: graph[u])
        if(!vis[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n){
//        cin.ignore();
        graph.assign(n, vi());
        for (int i = 0; i < n - 1; ++i) {
            string s; cin >> s;
            for (int j = 0; j < s.size(); ++j) {
                if(s[j] == '1')
                    graph[i].push_back(j + i + 1);
                else
                    graph[i + j + 1].push_back(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vis.assign(n, 0);
            dfs(i);

            if(vis == vi(n, 1))
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
