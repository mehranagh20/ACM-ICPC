//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define S second
#define pb push_back

vii dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool ok(vs &grid, string str, int i, int j) {
    int n = grid.size(), m = grid[0].size();
    for(auto &e: str) {
        ii tmp = dir[e - '0'];
        i += tmp.first, j += tmp.second;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(grid[i][j] == '#') return false;
        if(grid[i][j] == 'E') return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    sort(dir.begin(), dir.end());
    int ans = 0;
    int n, m; cin >> n >> m;
    vs grid(n, string(m, ' '));
    int s, t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') s = i, t = j;
        }
    }
    string str; cin >> str;
    do {
        if(ok(grid, str, s, t)) ans++;
    } while(next_permutation(dir.begin(), dir.end()));
    cout << ans << endl;


    return 0;
}
