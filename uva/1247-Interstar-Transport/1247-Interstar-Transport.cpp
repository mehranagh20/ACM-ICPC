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

void floyd(vvi &adjMat, vvii &path, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) {
                if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j] || (adjMat[i][j] == adjMat[i][k] + adjMat[k][j] && path[i][j].second > path[i][k].second + path[k][j].second)) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    path[i][j].second = path[i][k].second + path[k][j].second;
                    path[i][j].first = path[k][j].first;
                }
            }
}

void pr(int i, int j, vvii &path, vector<char> &ans) {
    if(i != j) pr(i, path[i][j].first, path, ans);
    ans.push_back((char)(j + 65));
}

int main() {
    int n, m; cin >> n >> m;
    vvi adjMat(n, vi(n, inf));
    vvii path(n, vii(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) path[i][j] = {i, 1};
    for(int i = 0; i < m; i++) {
        int c;
        char a, b; cin >> a >> b >> c;
        adjMat[a - 65][b - 65] = adjMat[b - 65][a - 65] = c;
    }
    floyd(adjMat, path, n);
    for(int i = 0; i < n; i++) path[i][i].first = i;
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        char a, b; cin >> a >> b;
        vector<char> ans;
        pr(a - 65, b - 65, path, ans);
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
        cout << endl;
    }

    return 0;
}
