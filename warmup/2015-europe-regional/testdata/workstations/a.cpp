//In The Name Of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
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
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

bool comp(ii & a, ii & b){
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);

    ll n, m;
    while(cin >> n >> m) {
        int ans = 0;
        vii nums;
        vi st;
        for (ll j = 0; j < n; ++j) {
            ll a, b; cin >> a >> b;
            nums.push_back(ii(a, b));
            st.push_back(a);
        }
        sort(nums.begin(), nums.end(), comp);
        sort(st.begin(), st.end());
        vi flag(n, 1);

        for (ll i = 0; i < n; ++i) {
            if(flag[i]) ans++;

            ll beg = nums[i].first + nums[i].second, end = beg + m;
            auto bit = lower_bound(st.begin(), st.end(), beg);

            if(bit != st.end() && *bit <= end){
                auto eit = upper_bound(st.begin(), st.end(), end);

                ull a = bit - st.begin(), b = eit - st.begin();
                auto it = upper_bound(flag.begin() + a, flag.begin() + b, 0);

                if(it != flag.begin() + b)
                    flag[it - flag.begin()] = 0;
            }
        }
        cout << n - ans << endl;
    }



    return 0;
}