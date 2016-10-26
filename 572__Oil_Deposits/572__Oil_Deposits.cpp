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

int n, m;
vector<vector<char>> graph;

vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void dfs(int i, int j) {
    if(i >= n || i < 0 || j >= m || j < 0) return;
    if(graph[i][j] != '@') return;
    graph[i][j] = '*';
    for(auto &e : moves) dfs(i + e.first, j + e.second);
}

int main() {
    while(cin >> n >> m && (m || n)) {
        graph.clear(); graph.resize(n, vector<char>(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> graph[i][j];
        int ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(graph[i][j] == '@') {
                    ans++;
                    dfs(i, j);
                }
        cout << ans << endl;
    }

    return 0;
}
