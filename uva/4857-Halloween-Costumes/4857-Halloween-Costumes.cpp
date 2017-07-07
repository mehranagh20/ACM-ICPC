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

vi parties;

vvi memo;

int solve(int i, int j) {
    if(i == j) return 1;
    if(j < i) return 0;
    int &now = memo[i][j];
    if(now != -1) return now;
    now = solve(i, j - 1) + 1;
    int ind = -1;
    for(int k = j - 1; k >= i; k--) if(parties[k] == parties[j]) {
            now = min(now, solve(i, k) + solve(k + 1, j - 1));
        }
    return now;

}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        int n, m; cin >> n >> m;
        parties.assign(n, -1);
        for(auto &e: parties) cin >> e;
        memo.assign(n + 10, vi(n + 10, -1));
        cout << solve(0, n - 1) << endl;
    }

    return 0;
}
