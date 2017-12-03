/*
In rec, only consider values of the form ceil(N/k), for some k.
For each n, loop over all 2 <= k <= n.
Complexity: O(N/1 + N/2 + N/3 + ...) = O(N*log(N))
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, T, C, dp[1000001];

ll rec(ll n) {
	if (n <= 1) return 0;	
	if (dp[n] != -1) return dp[n];
	
	ll res = LLONG_MAX;
	for (ll k = 2; k <= n; k++) {
		res = min(res,(k-1)*C + T + rec((n+k-1)/k));
	}
	return dp[n] = res;
}

int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N >> T >> C;
	cout << rec(N) << endl;
}
