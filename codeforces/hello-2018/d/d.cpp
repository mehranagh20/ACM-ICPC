//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
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
#define S second
#define pb push_back

vector<pair<pair<ll, ll>, int>> nums;
ll n, t;

bool solve(ll x) {
    ll nm = 0;
    ll tt = t;
    for(int i = 0; i < n; i++) {
        auto e = nums[i].first;
        if(e.first > tt) break;
        if(e.second >= x) tt -= e.first, nm++;
    }
    return nm >= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> t;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i].first.second >> nums[i].first.first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
    ll l = 0, h = n;
    vector<int> ans;
    while(l <= h) {
        ll mid = (l + h) / 2;
        if(solve(mid)) l = mid + 1;
        else h = mid - 1;
    }
    ll x = l - 1;
    for (int i = 0; i < n; ++i) {
        if(nums[i].first.second >= x) ans.push_back(nums[i].second);
    }
    cout << x << endl << x << endl;
    if(x) {
        cout << ans[0] + 1;
        for (int i = 1; i < x; i++) cout << " " << ans[i] + 1;
    }
    cout << endl;

    return 0;
}
