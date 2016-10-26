//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, m; cin >> n >> m;
        vvi graph(n + m, vi(n + m, inf));
        for(int i = 0; i < n + m; i++) graph[i][i] = 0;
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a][b] = graph[b][a] = 2;
            graph[n + i][a] = graph[a][n + i] = 1;
            graph[n + i][b] = graph[b][n + i] = 1;
        }
        for (int k = 0; k < n + m; k++)
            for (int i = 0; i < n + m; i++)
                for (int j = 0; j < n + m; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        int mx = inf;
        for(int i = 0; i < n + m; i++) {
            int tmp = -inf;
            for(int j = 0; j < n; j++) tmp = max(tmp, graph[i][j]);
            mx = min(mx, tmp);
        }
        cout << "Case #" << i << ":" << endl;
        cout << mx << endl << endl;
    }

    return 0;
}