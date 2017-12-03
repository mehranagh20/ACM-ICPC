#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, T, C, dp[1000001];

int main() {
	cin >> N >> T >> C;
	dp[1] = 0;
	for (ll n = 2; n <= N; n++) {
		auto f = [&](ll k) {
			return (k-1)*C + T + dp[(n+k-1)/k];
		};
		ll a = 2, b = n;
		while (b-a > 2) {
			ll c = a + (b-a)/3, d = a + 2*(b-a)/3;
			if (f(c) <= f(d)) b = d; else a = c;
		}
		dp[n] = LLONG_MAX;
		for (ll k = a-3; k <= a+3; k++) {
			if (k >= 2 && k <= n) dp[n] = min(dp[n],f(k));
		}
		for (ll k = 2; k <= n; k++) {
			cerr << k << ": " << f(k) << ", ";
		}
		cerr << endl;
	}
	cout << dp[N] << endl;
}
