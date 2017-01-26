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

ll h(ll n) {
    ll prev, ans = 0, till = sqrt(n); // idk why till sqrt(n), but i'll explain how rest of alg works :)
    // n / i = k means that the last number d that n / d = i is k
    // n / (i + 1) = s means the last number d that n / d = (i + 1) is s, then if n / (s + 1) = i
    // now we have the first number (s + 1) such that n / (s + 1) = r and the last number x such that n / x = r
    // so we calculated the s + 1 to x range and we know that all n / i for all i in this range is r so ans += r * (s - x)
    // hope it helps :)
    for(int i = 1; i <= till; i++) {
        ans += n / i;
        ans += (i - 1) * (prev - (n / i));
        prev = n / i;
    }
    ans += (till) * (prev - till);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        cout << h(n) << endl;
    }

    return 0;
}