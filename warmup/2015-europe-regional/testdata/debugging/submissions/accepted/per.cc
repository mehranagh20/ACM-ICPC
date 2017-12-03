#include <bits/stdc++.h>
using namespace std;

long long cost[1<<20], N, T, C;

long long Cost(int N) {
	if (N <= 1) return 0;
	long long &r = cost[N];
	if (r == -1) {
		r = 1LL<<62;
		for (int x = 2; x <= N; ++x)
			r = min(r, C*(x-1) + T + Cost((N+x-1)/x));
	}
	return r;
}

int main(void) {
	scanf("%lld%lld%lld", &N, &T, &C);
	memset(cost, -1, sizeof(cost));
	printf("%lld\n", Cost(N));
	return 0;
}
