//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
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

#define inf 1000000000
#define eps 1e-9

void floyd(vvi &adjMat, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int n, m, tc = 1;
    while(cin >> n >> m && (n || m)) {
        int ind = 0;
        vector<string> rvMP(n);
        vvi graph(n, vi(n, inf));
        for(int i = 0; i < n; i++) {
            graph[i][i] = 0;
            string a; cin >> a;
            rvMP[i] = a;
        }
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c; a--; b--;
            graph[a][b] = graph[b][a] = c;
        }
        floyd(graph, n);
        int ansIn = 0, tot = inf;
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) tmp += graph[j][i];
            if(tmp < tot) {
                tot = tmp;
                ansIn = i;
            }
        }
        cout << "Case #" << tc++ << " : " << rvMP[ansIn] << endl;
    }

    return 0;
}
