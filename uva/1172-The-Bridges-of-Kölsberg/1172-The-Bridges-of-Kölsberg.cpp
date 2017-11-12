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

vector<pair<string, int>> fc, sc;
vvii memo;

ii solve(int i, int j) {
    if(i >= fc.size() || j >= sc.size()) return ii(0, 0);
    ii &now = memo[i][j], cur;
    if(now != ii(-1, -1)) return now;

    if(fc[i].first == sc[j].first) {
        cur = solve(i + 1, j + 1);
        now = ii(cur.first + fc[i].second + sc[j].second, cur.second + 1);
    }

    cur = solve(i, j + 1);
    if(now.first < cur.first || (now.first == cur.first && now.second > cur.second))
    now = cur;

    cur = solve(i + 1, j);
    if(now.first < cur.first || (now.first == cur.first && now.second > cur.second))
        now = cur;

    return now;

}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        fc.assign(n, pair<string, int>("", 0));
        for(auto &e: fc) cin >> e.first >> e.first >> e.second;

        n; cin >> n;
        sc.assign(n, pair<string, int>("", 0));
        for(auto &e: sc) cin >> e.first >> e.first >> e.second;

        memo.assign(fc.size() + 10, vii(sc.size() + 10, ii(-1, -1)));
        ii ans = solve(0, 0);
        if(ans.first == inf && ans.second == inf) cout << 0 << " " << 0 << endl;
        else cout << ans.first << " " << ans.second << endl;
    }


    return 0;
}
