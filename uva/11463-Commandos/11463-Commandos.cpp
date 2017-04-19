//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

void floyd(vvi &adjMat) {
    for(int k = 0; k < adjMat.size(); k++) for(int i = 0; i < adjMat.size(); i++) for(int j = 0; j < adjMat.size(); j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main() {
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, m; cin >> n >> m;
        vvi graph(n, vi(n, inf));
        for(int i = 0; i < n; i++) graph[i][i] = 0;
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            if(a == b) continue;
            graph[a][b] = graph[b][a] = 1;
        }
        floyd(graph);
        int ans = -inf, s, d; cin >> s >> d;
        for(int i = 0; i < n; i++) ans = max(ans, graph[s][i] + graph[i][d]);
        cout << "Case " << i << ": " << ans << endl;
    }


    return 0;
}
