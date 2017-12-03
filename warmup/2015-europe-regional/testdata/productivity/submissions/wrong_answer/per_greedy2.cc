/* Note: this solution assumes time limit is 2 seconds.  When run in
 * an environment where time limit is different, adjust the timelim
 * constant below.
 *
 * Local search from initial feasible configuration found greedily
 */
#include <bits/stdc++.h>

const double timelim = 1.950; // seconds

using namespace std;
const int oo = 1<<30;
typedef pair<int, int> Ival;
int N, P;
Ival ival[220];

int prod(const vector<Ival> &L) {
	int lf = -oo, rt = oo;
	if (L.empty()) return 0;
	for (auto I: L) {
		lf = max(lf, I.first);
		rt = min(rt, I.second);
	}
	return rt-lf;
}

struct swap1 {
	int fl, fi, tl; long long val;
	swap1(int fl=0, int fi=0, int tl=0, long long val=0): fl(fl), fi(fi), tl(tl), val(val) {}
};

typedef enum {MAX, RND_LINEAR} swap_policy;

int solve_once(swap_policy policy) {
	vector<Ival> pline[500];
	int cnt = 0;
	for (int i = 0; i < N; ++cnt) {
		int j = i, rt = ival[i].second;
		while (j < N && ival[j].first < rt) {
			rt = min(rt, ival[j].second);
			pline[cnt].push_back(ival[j]);
			++j;
		}
		i = j;
	}
	assert(cnt <= P);
	//	fprintf(stderr, "init use %d/%d\n", cnt, P);
	while (true) {
		vector<swap1> swaps;
		long long totgain = 0;
		int cprods[500], cleft[500], cright[500];
		for (int i = 0; i < cnt; ++i) {
			cleft[i] = -oo;
			cright[i] = oo;
			for (auto x: pline[i]) {
				cleft[i] = max(cleft[i], x.first);
				cright[i] = min(cright[i], x.second);
			}
			cprods[i] = cright[i]-cleft[i];
		}
		cleft[cnt] = -oo;
		cright[cnt] = oo;
		cprods[cnt] = 0;
		for (int l = 0; l < cnt; ++l) {
			if (pline[l].size() <= 1) continue;
			for (int i = 0; i < pline[l].size(); ++i) {
				Ival x = pline[l][i];
				int delta1 = 0;
				if (x.first == cleft[l] || x.second == cright[l]) {
					pline[l][i] = Ival(-oo, oo);
					delta1 = prod(pline[l]) - cprods[l];
					pline[l][i] = x;
				} 
				for (int k = 0; k <= cnt && k < P; ++k) {
					if (k == l) continue;
					int tprod = min(cright[k], x.second) - max(cleft[k], x.first);
					//					fprintf(stderr, "add (%d %d) to %d -> %d\n",							x.first, x.second, k, tprod);
					if (tprod <= 0) continue;
					long long delta = delta1 + tprod-cprods[k];
					if (delta > 0) {
						//						fprintf(stderr, "  move %d %d -> %d => %lld\n", l, i, k, delta);
						swaps.push_back(swap1(l, i, k, delta));
						totgain += delta;
					}
				}
			}
		}
		if (swaps.empty()) break;
		swap1 choice;
		int x;
		switch (policy) {
		case MAX:
			for (auto s: swaps)
				if (s.val > choice.val)
					choice = s;
			break;
		case RND_LINEAR:
			x = random() % totgain;
			for (auto s: swaps) {
				x -= s.val;
				if (x < 0) {
					choice = s;
					break;
				}
			}
			break;
		}
		assert(choice.val > 0);
		//		fprintf(stderr, "go move (%d,%d) from line %d to %d for gain %d\n", pline[choice.fl][choice.fi].first, pline[choice.fl][choice.fi].second, choice.fl, choice.tl, choice.val);
		assert(choice.fi < pline[choice.fl].size());
		pline[choice.tl].push_back(pline[choice.fl][choice.fi]);
		pline[choice.fl].erase(pline[choice.fl].begin() + choice.fi);
		if (choice.tl == cnt) ++cnt;
	}
	int ans = 0;
	for (int i = 0; i < cnt; ++i) {
		//		for (auto x: pline[i]) fprintf(stderr, " [%d %d]", x.first, x.second);
		//		fprintf(stderr, "\n");
		ans += prod(pline[i]);
		//		assert(prod(pline[i]) > 0);
	}
	return ans;
}

int main(void) {
	clock_t start = clock();
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; ++i) scanf("%d%d", &ival[i].first, &ival[i].second);
	sort(ival, ival+N);
	int ans = solve_once(MAX);
	srand(time(NULL));
	while (true) {
		clock_t dur = clock()-start;
		if (double(dur)/CLOCKS_PER_SEC > timelim) break;
		ans = max(ans, solve_once(RND_LINEAR));
	}
	//	for (int i = 0; i < 500; ++i) ans = max(ans, solve_once(RND_SQUARE));
	printf("%d\n", ans);
	return 0;
}
