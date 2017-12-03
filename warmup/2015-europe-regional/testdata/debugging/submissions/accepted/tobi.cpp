#include <iostream>
#include <climits>

using namespace std;

long long N, T, C, table[1000005];

long long rec(int N) {
	if (N <= 1) return 0;
	if (table[N] != LLONG_MAX) return table[N];
	for (int i = 1; i < N; i++) {
		long long maxSegLen = (N+i)/(i+1);
		table[N] = min(table[N], i*C + T + rec(maxSegLen));
	}
	return table[N];
}

int main() {
	cin >> N >> T >> C;
	for (int i = 0; i <= N; i++) table[i] = LLONG_MAX;
	cout << rec(N);
	return 0;
}
