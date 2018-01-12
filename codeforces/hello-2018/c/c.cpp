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

vector<ull> nums;

ull solve(ull l) {
    if(l == 0) return 0;
    ull ans = 0, cur = 1;
    for(int i = 0; i < nums.size(); i++) {
        bool ok = true;
        ull need = (l / cur) * nums[i];
        if(cur <= l) {
            ull cur2 = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if(cur2 > l) break;
                ull need2 = (l / cur2) * nums[j];
                if(need2 < need) {
                    ok = false;
                    break;
                }
                cur2 *= 2;
            }
        }
        if(ok) {
            ull nx = solve(l - ((l / cur) * cur));
            ans = need + nx;
            i++, cur *= 2;
            while(i < nums.size()) {
                if(cur > l) ans = min(ans, nums[i]);
                i++;
            }
            return ans;
        }
        cur *= 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    ull n, l; cin >> n >> l;
    nums.resize(n);
    for(auto &e: nums) cin >> e;
    cout << solve(l) << endl;

    return 0;
}
