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


int main() {
    vvi grid(1500, vi(1500, 0));
    int mx = 750;
    int cur = 1, i = mx + 1, j = mx;
    grid[mx][mx] = 1;
    vii ans(100010);
    while(cur < 100000) {
        while(grid[i - 1][j]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            j--;
        }
        while(grid[i - 1][j + 1]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            i--;
        }
        while(grid[i][j + 1]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            i--, j++;
        }
        while(grid[i + 1][j]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            j++;
        }
        while(grid[i + 1][j - 1]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            i++;
        }
        while(grid[i][j - 1]) {
            grid[i][j] = ++cur;
            ans[cur] = ii(i - mx, j - mx);
            i++, j--;
        }
    }
    int n;
    while(cin >> n) cout << ans[n].second << " " << ans[n].first << endl;

    return 0;
}