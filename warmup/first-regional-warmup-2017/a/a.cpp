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

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m) {
        graph.assign(n, vi(n, inf));

        int mx = -inf;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }
        for (int i1 = 0; i1 < n; ++i1) {
            graph[i1][i1] = 0;
        }


        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) // this time, we need to use if statement
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < n; ++i) {
                mx = max(mx, graph[l][i]);
            }
        }
        int a, b, c;
        cin >> a >> b >> c;
        double ans = max(max((double)mx / a, (double)mx / b), (double)mx / c);

        cout << (int)(ceil(ans) + eps) << endl;
    }



    return 0;
}
