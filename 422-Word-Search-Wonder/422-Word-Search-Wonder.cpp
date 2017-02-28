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
ii st, fi;
int n;

bool solve(string &word, int i, int j) {
    for(int r = 0; r < 8; r++) {
        int ind = 1;
        int x = i + xdirs[r], y = j + ydirs[r];
        if(x >= n || x < 0 || y >= n || y < 0 || word[ind] != grid[x][y]) continue;
        i += xdirs[r], j += ydirs[r];
        while(word[ind] == grid[i][j]) {
            ind++;
            if(ind == word.size()) {
                fi = {i, j};
                return true;
            }
            i += xdirs[r], j += ydirs[r];
            if(i >= n || i < 0 || j >= n || j < 0) break;
        }
    }
    return false;
}



int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    grid.assign(n, "");
    for(auto &e : grid) cin >> e;
    string str;
    while(cin >> str && str != "0") {
        bool found = false;
        for(int i = 0; i < n && !found; i++) for(int j = 0; j < n && !found; j++) {
            if(grid[i][j] == str[0]) {
                if(solve(str, i, j)) {
                    found = true;
                    st = {i, j};
                }
            }
        }
        if(found) cout << st.first + 1 << "," << st.second + 1 << " " << fi.first + 1 << "," << fi.second + 1 << endl;
        else cout << "Not found\n";
    }


    return 0;
}
