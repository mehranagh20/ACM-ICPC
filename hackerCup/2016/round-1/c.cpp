//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

#define inf 1000000000
#define eps 1e-9

vvi graph, memo;
vii works;
int n, k;

ll solve(int id, int loc) { // if this is the last there is no id + 1
    if(id == k - 1) return graph[loc][works[id].second];
    ll &now = memo[id][loc];
    if(now != -1) return now;
    now = inf;
    int s = works[id].first, d = works[id].second, ss = works[id + 1].first, dd = works[id + 1].second;
    now = min(graph[loc][d] + graph[d][ss] + solve(id +1, ss), graph[loc][ss] + graph[ss][d] + solve(id + 1, d));
    now = min(now, (ll)inf);
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        int m; cin >> n >> m >> k;
        graph.assign(n, vi(n, inf)), works.assign(k, ii(0, 0));
        for(int i = 0; i < n; i++) graph[i][i] = 0;
        for(int i = 0; i < m; i++) {
            ll a, b, c; cin >> a >> b >> c;
            a--, b--;
            graph[a][b] = graph[b][a] = min(graph[a][b], c);
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            works[i].first = a - 1, works[i].second = b - 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        memo.assign(k + 1, vi(n + 1, -1));
        int ans = solve(0, works[0].first) + graph[0][works[0].first];
        if(ans >= inf) cout << -1 << endl;
        else cout << ans << endl;
    }


    return 0;
}
