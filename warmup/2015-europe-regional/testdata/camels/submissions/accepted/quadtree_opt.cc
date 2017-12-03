#include <bits/stdc++.h>
using namespace std;
const int THRES = 50;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;
int a[200000], b[200000], c[200000], bp[200001], cp[200001];

struct qt {
	int l, b, w, cnt;
	vpii pts;
	qt *sub[4];
	qt(int l, int b, int w): l(l), b(b), w(w), cnt(0) { memset(sub, 0, sizeof(sub)); }
	int child(int x, int y) {
		return 2*(y >= b+w/2) + (x >= l+w/2);
	}
	void add(int x, int y) {
		if (++cnt == THRES) {
			for (pii p: pts) {
				int c = child(p.first, p.second);
				if (!sub[c]) sub[c] = new qt(l + (c&1)*w/2, b + (c&2)*w/4, w/2);
				sub[c]->add(p.first, p.second);
			}
			pts.clear();
		}
		if (cnt < THRES)
			pts.push_back(pii(x, y));
		else {
			assert(w > 1);
			int c = child(x, y);
			if (!sub[c]) sub[c] = new qt(l + (c&1)*w/2, b + (c&2)*w/4, w/2);
			sub[c]->add(x, y);
		}
	}
	int q(int x, int y, int &leaves) {
		if (x <= l || y <= b) { ++leaves; return 0; }
		if (x >= l+w-1 && y >= b+w-1) { ++leaves; return cnt; }
		int res = 0;
		if (cnt < THRES) {
			for (pii p: pts)
				res += p.first < x && p.second < y;
		} else 
			for (int i = 0; i < 4; ++i) if (sub[i]) res += sub[i]->q(x, y, leaves);
		return res;
	}
};

int main(void) {
	int n, w = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a+i);
	for (int i = 0; i < n; ++i) scanf("%d", b+i), bp[b[i]] = i;
	for (int i = 0; i < n; ++i) scanf("%d", c+i), cp[c[i]] = i;
	while (w <= n) w *= 2;
	qt T(0, 0, w);
	ll ans = 0;
	int ops = 0;
	for (int i = 0; i < n; ++i) {
		//		printf("go with point (%d, %d)\n", bp[a[i]], cp[a[i]]);
		ans += T.q(bp[a[i]], cp[a[i]], ops);
		T.add(bp[a[i]], cp[a[i]]);
	}
	printf("%lld\n", ans);
	fprintf(stderr, "%d ops\n", ops);
}
