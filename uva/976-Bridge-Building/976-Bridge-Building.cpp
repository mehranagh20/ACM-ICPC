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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int h, w;
vs grid;
vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void dfs(int i, int j) {
    if(i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != '#') return;
    grid[i][j] = '*';
    for(auto &e: moves) dfs(i + e.first, j + e.second);
}

vi cost;
vvi memo;
int s;
int solve(int j, int k) {
    if(k == 0) return 0;
    if(j >= w) return inf;
    int &now = memo[j][k];
    if(now != -1) return now;
    now = inf;
    for(int i = j; i < w; i++) now = min(now, solve(i + s + 1, k - 1) + cost[i]);
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> h >> w) {
        int b; cin >> b >> s;
        cost.assign(w, 0);
        grid.assign(h, "");
        for(int i = 0; i < h; i++) cin >> grid[i];
        dfs(h - 1, 0);

        cost.assign(w, 0);
        for(int j = 0; j < w; j++) {
            int tmp;
            for(int i = 0; i < h; i++) if(grid[i][j] == '*') {
                tmp = i - 1;
                break;
            }

            int num = 0;
            while(grid[tmp][j] != '#') num++, tmp--;
            cost[j] = num;
        }
        memo.assign(w + 10, vi(b + 10, -1));
        cout << solve(0, b) << endl;
    }


    return 0;
}
