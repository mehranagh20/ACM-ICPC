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

ll n, k;
vector<vector<ll>> memo;
vector<ll> nums;

ll solve(int i, int w) {
    if(i >= n) return 0;
    ll &ans = memo[i][w];
    if(ans != -1) return ans;
    ans = solve(i + 1, w == 0 ? 0 : w - 1);
    ans = max(ans, solve(i + 2, 0));
    ll r = k;
    for(int i = 0; i < w; i++) r = ((double)r * (2./3.));
    ans = max(ans, solve(i + 1, w + 1) + min(r, nums[i]));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    nums.assign(n, 0);
    for(auto &e: nums) cin >> e;
    memo.assign(n + 10, vector<ll>(k + 10, -1));
    cout << solve(0, 0) << endl;

    return 0;
}
