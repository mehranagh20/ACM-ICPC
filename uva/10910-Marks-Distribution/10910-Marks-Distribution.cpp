#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vector<vector<ll>> memo;
int n, t, p;

ll solve(int id, int rem) {
    if(id == n)
        return rem == 0 ? 1 : 0;
    if(rem < 0) return 0;
    if(memo[id][rem] != -1) return memo[id][rem];
    ll ans = 0;
    for(int i = p; i <= t; i++) ans += solve(id + 1, rem - i);
    return memo[id][rem] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> t >> p;
        memo.clear(); memo.resize(n + 2, vector<ll>(t + 5, -1));
        cout << solve(0, t) << endl;
    }

    return 0;
}