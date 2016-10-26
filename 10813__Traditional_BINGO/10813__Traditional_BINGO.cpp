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
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        vector<int> rows(5, 0), cols(5, 0);
        int fdiagonal = 1, sdiagonal = 1;
        rows[2] = cols[2] = 1;
        vector<ii> grid(76, ii(-1, -1));
        for(int i = 0; i < 5; i++) {
            if(i == 2) {
                int a, b, c, d; cin >> a >> b >> c >> d;
                grid[a] = ii(i, 0), grid[b] = ii(i, 1), grid[c] = ii(i, 3), grid[d] = ii(i, 4);
            }
            else {
                for(int j = 0; j < 5; j++) {
                    int a; cin >> a;
                    grid[a] = ii(i , j);
                }
            }
        }
        int ans;
        for(ans = 0; ans < 75; ans++) {
            int a; cin >> a;
            if(grid[a].first == -1) continue;
            if(grid[a].first == grid[a].second) fdiagonal++;
            if(grid[a].first + grid[a].second == 4) sdiagonal++;
            rows[grid[a].first]++, cols[grid[a].second]++;
            if(fdiagonal == 5 || rows[grid[a].first] == 5 || cols[grid[a].second] == 5 || sdiagonal == 5) {
                for(int i = ans + 1; i < 75; i++) cin >> a;
                break;
            }
        }
        cout << "BINGO after " << ans + 1 << " numbers announced" << endl;
    }
}