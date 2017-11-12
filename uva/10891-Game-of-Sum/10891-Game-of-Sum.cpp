//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

vi nums;
vvi memo;
ll n, sec;

ll solve(int i, int j) {
    if(i > j) return 0;
    ll &now = memo[i][j];
    if(now != -1) return now;
    ll s = 0;
    now = -inf;

    ll tot = 0;
    for(int k = i; k <= j; k++) tot += nums[k];

    for(int k = i; k <= j; k++) {
        s += nums[k];
        ll r = solve(k + 1, j);
        if(now < tot - r) {
            now = tot - r;
            if(i == 0 && j == n - 1) sec = r;
        }
    }
    s = 0;
    for(int k = j; k >= i; k--) {
        s += nums[k];
        ll r = solve(i, k - 1);
        if(tot - r > now) {
            now = tot - r;
            if(i == 0 && j == n - 1) sec = r;
        }
    }

    return now;

}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n && n) {
        nums.assign(n, 0);
        for(auto &e: nums) cin >> e;
        memo.assign(n, vi(n, -1));
        ll cur = solve(0, n - 1);
        cout << cur - sec << endl;

    }


    return 0;
}
