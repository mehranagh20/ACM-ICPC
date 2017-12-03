#include <bits/stdc++.h>
using namespace std;
const int oo = 1<<30;

int N, best[220][220][220];
pair<int, int> ival[220];

int Best(int i, int P, int r) {
	if (P == 0 || i == N) return i < N || P || r < oo ? -oo : 0;
	if (r == oo) r = i;
	if (ival[r].second <= ival[i].first) return -oo;
	int &res = best[i][P][r], nr = ival[i].second < ival[r].second ? i : r;
	if (res == -1)
		res = max(Best(i+1, P, nr),
				  max(ival[i].second-ival[i].first + Best(i+1, P-1, r),
					  ival[nr].second-ival[i].first + Best(i+1, P-1, oo)));
	return res;
}

int main(void) {
	int P;
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; ++i) scanf("%d%d", &ival[i].first, &ival[i].second);
	sort(ival, ival+N);
	memset(best, -1, sizeof(best));
	printf("%d\n", Best(0, P, oo));
	return 0;
}
