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

#define inf 1000000000
#define eps 1e-9

vs grid;
vi xdirs = {0, 0, 1, -1, 1, -1, 1, -1}, ydirs = {1, -1, 0, 0, 1, 1, -1, -1};
int n, m;

bool solve(string &word, int i, int j) {
    for(int r = 0; r < 8; r++) {
        int ind = 1;
        int x = i + xdirs[r], y = j + ydirs[r];
        if(x >= n || x < 0 || y >= m || y < 0 || tolower(word[ind]) != tolower(grid[x][y])) continue;
        while(tolower(word[ind]) == tolower(grid[x][y])) {
            ind++;
            if(ind == word.size()) return true;
            x += xdirs[r], y += ydirs[r];
            if(x >= n || x < 0 || y >= m || y < 0) break;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        cin >> n >> m;
        grid.assign(n, "");
        for(auto &e : grid) cin >> e;
        int k; cin >> k;
        for(int i = 0; i < k; i++) {
            string word; cin >> word;
            bool found = false;
            for(int i = 0; i < n && !found; i++) for(int j = 0; j < m && !found; j++) {
                if(tolower(grid[i][j]) == tolower(word[0])) {
                    if(solve(word, i, j)) {
                        found = true;
                        cout << i + 1 << " " << j + 1 << endl;
                    }
                }
            }
        }
    }


    return 0;
}
