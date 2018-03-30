//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<ld, ld> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
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
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back


int main() {
    ios::sync_with_stdio(0);
    int n, u; cin >> n >> u;
    vi nums(n);
    for(auto &e: nums) cin >> e;
    ld ans = -1;
    for(int i = 0; i < n - 2; i++) {
        int j = i + 1;
        auto it = lower_bound(nums.begin(), nums.end(), nums[i] + u);
        if(it == nums.end()) it = nums.end() - 1;
        if(*it > nums[i] + u) it--;
        int k = it - nums.begin();
        if(k == i || k == j) continue;

        ans = max(ans, (ld)(nums[k] - nums[j]) / (nums[k] - nums[i]));
    }

    if(ans == -1) cout << -1 << endl;
    else
        cout << fixed << setprecision(15) << ans << endl;

    return 0;
}