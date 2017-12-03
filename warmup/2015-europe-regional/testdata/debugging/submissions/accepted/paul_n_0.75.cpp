/*
In rec, only consider values of the form ceil(N/k), for some k.
For each n, there are only O(sqrt(n)) distinct values ceil(n/k).
For fixed t = ceil(n/k), the minimal such k can be found in O(1).
Complexity: O(N^(3/4)) with big constant factor
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, T, C, dp[1000001];

inline ll h(ll n, ll k) { return (n+k-1)/k; }

ll rec(ll n) {
	if (n <= 1) return 0;	
	if (dp[n] != -1) return dp[n];
	
	ll res = LLONG_MAX;
	for (ll k = 2; k <= n; k++) {
		res = min(res,(k-1)*C + T + rec(h(n,k)));
		if (k*k > n) break;
	}
	// t >= 2: ceil(n/k) == t <=> (t-1)*k < n <= t*k <=> k > n/(t-1) && k <= n/t
	for (ll t = 2; t <= n; t++) {
		ll k = n/(t-1) + 1;
		if (k*k <= n) break;
		if (k > n/t) continue;
		res = min(res,(k-1)*C + T + rec(t));
	}
	// t == 1: ceil(n/k) == 1 <=> k >= n
	res = min(res,(n-1)*C + T);
	return dp[n] = res;
}

int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N >> T >> C;
	cout << rec(N) << endl;
}
