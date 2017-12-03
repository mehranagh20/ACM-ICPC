/* 1. Find feasible assignment using smallest number of lines.
 * 2. If there are empty lines, pick the largest interval and
 *    permanently assign that to an empty line.  Goto 1.
 * 3. Use dynprog to find best solution where each line gets assigned
 *    a contiguous subsequence of workers.
 */
#include <bits/stdc++.h>
using namespace std;
const int oo = 1<<30;

int N;
pair<int, int> ival[220];

int best[250][250];
int Best(int i, int p) {
	if (i == N) return 0;
	if (!p) return -oo;
	int &r = best[i][p];
	if (r == -1) {
		r = -oo;
		int lf = ival[i].first, rt = ival[i].second;
		for (int j = i; j < N && lf < rt; ++j) {
			lf = ival[j].first;
			rt = min(rt, ival[j].second);
			if (rt > lf) r = max(r, rt-lf + Best(j+1, p-1));
		}
	}
	return r;
}

int main(void) {
	int P;
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; ++i) scanf("%d%d", &ival[i].first, &ival[i].second);
	sort(ival, ival+N);
	int pline[300];
	int tot = 0;
	while (true) {
		int cnt = 0, val = 0;
		for (int i = 0; i < N; ++cnt) {
			int j = i, rt = ival[i].second;
			while (j < N && ival[j].first < rt) {
				rt = min(rt, ival[j].second);
				pline[j] = cnt;
				++j;
			}
			val += rt - ival[j-1].first;
			i = j;
		}
		assert(cnt <= P);
		//		fprintf(stderr, "cnt = %d, P = %d\n", cnt, P);
		if (cnt == P) {
			break;
		}
		int b = 0;
		for (int i = 0; i < N; ++i)
			if (ival[i].second-ival[i].first > ival[b].second-ival[b].first)
				b = i;
		//		fprintf(stderr, "take ival %d %d by itself\n", ival[b].first, ival[b].second);
		tot += ival[b].second-ival[b].first;
		rotate(ival+b, ival+b+1, ival+N);
		--N;
		--P;
	}
	memset(best, -1, sizeof(best));
	tot += Best(0, P);
	printf("%d\n", tot);
	return 0;
}
