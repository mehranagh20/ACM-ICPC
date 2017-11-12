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

int n, m, ans;
viii check_points;
vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(int i, int j, int step, int current_point, vector<vector<bool>> &vis) {
    if(i == 0 && j == 1 && step < n * m) return;
    if(step == m * n && (i != 0 || j != 1)) return;
    if(step == m * n && i == 0 && j == 1) {
        ans++;
        return;
    }
    if(current_point < 3) {
        int to_get = check_points[current_point].first;
        int need = abs(i - check_points[current_point].second.first) + abs(j - check_points[current_point].second.second);
        if(step + need > to_get) return;
        if(check_points[current_point].second.first == i && check_points[current_point].second.second == j) {
            if(step == to_get) current_point++;
            else return;
        }
    }

    for(auto &nei: moves)
        if(i + nei.first >= 0 && i + nei.first < n && j + nei.second >= 0 && j + nei.second < m && !vis[i + nei.first][j + nei.second]) {
            vis[i + nei.first][j + nei.second] = true;
            solve(i + nei.first, j + nei.second, step + 1, current_point, vis);
            vis[i + nei.first][j + nei.second] = false;
        }
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> m && (n || m)) {
        check_points.clear();
        int all = m * n;
        for(int i = 1; i <= 3; i++) {
            int a, b; cin >> a >> b;
            check_points.push_back(iii(i * all / 4, ii(a, b)));
        }
        ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        solve(0, 0, 1, 0, vis);
        cout << ans << endl;
    }


    return 0;
}
