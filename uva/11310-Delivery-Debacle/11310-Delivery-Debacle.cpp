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

int n;
vector<ll> memo;

ll solve(int id) {
    if(id == n) return 1;
    if(id > n) return 0;
    if(memo[id] != -1) return memo[id];
    ll &ans = memo[id];
    ans = 0;
    ans += solve(id + 1) + 4 * solve(id + 2) + 2 * solve(id + 3);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        memo.assign(n + 1, -1);
        cout << solve(0) << endl;
    }

    return 0;
}
