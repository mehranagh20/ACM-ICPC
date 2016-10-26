#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9
#define mod 1000000

vi memo;

ll solve(int i) {
    if(i == 0) return 1;
    if(memo[i] != -1) return memo[i];
    ll ans = 0;
    ans += (solve(i - sqrt(i)) % mod + solve(log(i)) % mod + solve(i * pow(sin(i), 2)) % mod) % mod;
    return memo[i] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    int q;
    memo.resize(1000001, -1);
    while(cin >> q && q != -1)
        cout << solve(q) << endl;

    return 0;
}