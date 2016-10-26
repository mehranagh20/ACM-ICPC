//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vector<vector<char>> fild;
vii moves;
int m, n;
char l, w = 0;

int rIndex(int i) {
    if(i == -1) return n - 1;
    if(i == n) return 0;
    else return i;
}

int dfs(int i, int j) {
    fild[i][j] = w;
    int ans = 1;
    for(auto &e : moves) {
        if(i + e.first < 0 || i + e.first >= m) continue;
        int tmpJ = rIndex(j + e.second);
        if(fild[i + e.first][tmpJ] == l) ans += dfs(i + e.first, tmpJ);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);

    moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    fild.resize(21, vector<char>(21));
    while(cin >> m >> n) {
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> fild[i][j];
        int currI, currJ; cin >> currI >> currJ;
        l = fild[currI][currJ];
        dfs(currI, currJ);
        int ans = 0;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
                if(fild[i][j] == l) ans = max(ans, dfs(i, j));
        cout << ans << endl;
    }

    return 0;
}