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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    vi fib = {1, 2};
    for(int i = 2; i < 100; i++) fib.push_back(fib[i - 1] + fib[i - 2]);
    map<ll, ll> mp;
    for(int i = 0; i < 100; i++) mp[fib[i]] = i + 1;
    int tc; cin >> tc;
    while(tc--) {
        ll n, mx = -1; cin >> n;
        vi nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i], mx = max(mx, mp[nums[i]]);
        string ans(mx, ' '), tmp, txt;
        cin.ignore(100, '\n'); getline(cin, tmp);
        for(auto &e : tmp) if(isalpha(e) && isupper(e)) txt += e;
        for(int i = 0; i < nums.size(); i++)
            ans[mp[nums[i]] - 1] = txt[i];
        cout << ans << endl;

    }

    return 0;
}
