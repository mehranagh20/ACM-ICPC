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

#define inf 1000000000000000ULL
#define eps 1e-9

ll n, t, p;

vi memo;
ll solve(int i) {
    if(i == 1) return 0;
    ll &ans = memo[i];
    if(ans != -1) return ans;
    ans = inf;
    for (int j = 1; j < i; ++j) {
        ans = min(ans, j * p + solve(ceil((double)i / (j + 1))) + t);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> t >> p) {
        memo.assign(n + 1, -1);
        cout << solve(n) << endl;
    }

    return 0;
}
