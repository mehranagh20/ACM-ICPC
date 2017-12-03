// C++ translation of Java submission
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
int N, M, cnt, a, b, endtimes[350000], vals[350000];
bool used[350000];

bool removeBiggestInTheRange(int from, int to) {
	int *index = lower_bound(vals, vals + N, to + 1); //+1 needed otherwise somewhere in the middle if all elements == to
	if (index == vals+N) index--; // shift by one if necessary

	while (index >= vals && *index >= from) {
		if (*index <= to && !used[index-vals]) {
			used[index-vals]=true;
			return true;
		}
		index--;
	}
	return false; //not found	
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	FOR(i, 0, N) {
		cin >> a >> b;
		endtimes[i] = a + b + M;
		vals[i] = a;
	}
	sort(endtimes, endtimes + N);
	sort(vals, vals + N);

	for (int i = N-1;  i >= 0; i--) {
		if (removeBiggestInTheRange(endtimes[i]-M, endtimes[i])) cnt++;
	}
	cout << cnt << endl;

	return 0;
}
