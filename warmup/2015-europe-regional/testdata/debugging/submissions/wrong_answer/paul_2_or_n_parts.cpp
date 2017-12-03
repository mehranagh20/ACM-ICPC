#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, T, C, dp[1000001];

ll rec(ll n) {
	if (n <= 1) return 0;	
	if (dp[n] != -1) return dp[n];
	return dp[n] = min(C + T + rec((n+1)/2), (n-1)*C + T);
}

int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N >> T >> C;
	cout << rec(N) << endl;
}
