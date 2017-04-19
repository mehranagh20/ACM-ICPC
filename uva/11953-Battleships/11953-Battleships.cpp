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
int n;

void dfs(int i, int j) {
    fild[i][j] = 'f';
    for(auto &e : moves) {
        if(i + e.first < 0 || i + e.first >= n || j + e.second < 0 || j + e.second >= n) continue;
        if(fild[i + e.first][j + e.second] == '@' || fild[i + e.first][j + e.second] == 'x') dfs(i + e.first, j + e.second);
    }
}

int main() {
    ios::sync_with_stdio(0);

    moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    fild.resize(101, vector<char>(101));
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> n;
        for(int i = 0; i < n; i++) for (int j = 0; j < n ; j++) cin >> fild[i][j];
        int ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
                if(fild[i][j] == 'x') {
                    ans++;
                    dfs(i, j);
                }
        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}