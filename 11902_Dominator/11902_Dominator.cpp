#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vvi adjList, tmp;

void dfs(int v, vi &vis, int check) {
    vis[v] = 1;
    for(auto &e : adjList[v])
        if (!vis[e] && check != e) dfs(e, vis, check);
}

int main() {
    vvi &adj = adjList;
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ":" << endl;
        int n; cin >> n;
        adjList.clear(); adjList.resize(n);
        tmp.clear(); tmp.resize(n, vi(n, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                char c; cin >> c;
                if(c == '1') {
                    adjList[i].push_back(j);
                    tmp[i][j] = 1;
                }
            }
        vvi dominators(n, vi(n, 0));
        dfs(0, dominators[0], -1);
        for(int i = 1; i < n; i++)
                dfs(0, dominators[i], i);
        cout << "+"; for(int i = 0; i < 2 * n - 1; i++) cout << "-"; cout << "+" << endl;
        for(int i = 0; i < n; i++) {
            if(dominators[0][i]) cout << "|Y";
            else cout << "|N";
        }
        cout << "|" << endl;
        for(int i = 1; i < n; i++) {
            cout << "+"; for(int i = 0; i < 2 * n - 1; i++) cout << "-"; cout << "+" << endl;
            for (int j = 0; j < n; j++) {
                if (dominators[0][j] && !dominators[i][j] && j) cout << "|Y";
                else cout << "|N";
            }
            cout << "|" << endl;
        }
        cout << "+"; for(int i = 0; i < 2 * n - 1; i++) cout << "-"; cout << "+" << endl;
    }

    return 0;
}