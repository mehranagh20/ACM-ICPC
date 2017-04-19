//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

//this algorithm is absolutely stupid and inefficient... i will try to solve it again with better efficiency... but for now :|

vector<vector<char>> grid;
vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vvvi> memo;
int n;
char mx;

ll sol(int i, int j, char curr, int len) {
    if(i < 0 || j < 0 || i >= n || j >= n) return 0;
    if(grid[i][j] == '#') return 0;
    if(len < 0) return 0;
    if(isalpha(grid[i][j]) && grid[i][j] > curr) return 0;
    ll &an = memo[i][j][curr - 65][len];
    if(mx == grid[i][j] && mx == curr) return 1;
    if(an != -inf) return an;
    an = 0;
    int tmpCurr = grid[i][j] == curr ? curr + 1 : curr;
    for(auto &e : moves) {
        an += (sol(i + e.first, j + e.second, tmpCurr, len - 1));
        an %= 20437;
    }
    return an;

}

int main() {
    ios::sync_with_stdio(false);
    int tc = 1;
    while(cin >> n && n) {
        grid.clear(); grid.resize(n, vector<char>(n));
        mx = 'A';
        vii coor(26);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(isalpha(grid[i][j])) {
                    mx = max(mx, grid[i][j]);
                    coor[grid[i][j] - 65] = {i, j};
                }
            }
        bool found = false;
        cout << "Case " << tc++ << ": ";
        for(int i = 0; i < n * n * 10; i++) {
            memo.clear(); memo.resize(n, vvvi(n, vvi(mx - 63, vi(i + 1, -inf))));
            int ans = sol(coor[0].first, coor[0].second, 'A', i);
            if(ans > 0) {
                cout << i << " " << ans % 20437 << endl;
                found = true;
                break;
            }
        }
        if(!found) cout << "Impossible\n";


        }

    return 0;
}