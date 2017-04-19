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
int r, c, m, n, even, odd;
vii moves;
vvi grid;

void dfs(int i, int j) {
    if (i >= r || j >= c || i < 0 || j < 0 || grid[i][j]) return;
    for (auto &e : moves)
        if (!(i + e.first >= r || j + e.second >= c || i + e.first < 0 || j + e.second < 0) &&
            grid[e.first + i][e.second + j] != -1)
            grid[i][j]++;
    grid[i][j] & 1 ? odd++ : even++;
    for (auto &e : moves)
        dfs(e.first + i, e.second + j);
}

int main() {
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> r >> c >> m >> n;
        even = odd = 0;
        grid.clear(); grid.resize(r, vi(c, 0));
        set<ii> st;
        st = {{m,  n}, {-m, n}, {m,  -n}, {-m, -n}, {n,  m}, {-n, m}, {n,  -m}, {-n, -m}};
        moves.clear();
        for (auto it = st.begin(); it != st.end(); it++) moves.push_back(make_pair(it->first, it->second));
        int w; cin >> w;
        while (w--) {
            int a, b; cin >> a >> b;
            grid[a][b] = -1;
        }
        dfs(0, 0);
        cout << "Case " << i << ": " << even << ' ' << odd << endl;
    }

    return 0;
}