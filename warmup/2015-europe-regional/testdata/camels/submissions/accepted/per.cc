#include <bits/stdc++.h>
using namespace std;

int n, a[200000], x[200000], y[200000], bp[200001], cp[200001];

bool y_less(int i, int j) { return y[i] < y[j]; }
bool x_less(int i, int j) { return x[i] < x[j]; }

struct bit {
	vector<int> pts, cnt;
	bit(int *b, int *e): pts(vector<int>(b, e)), cnt(e-b) {
		sort(pts.begin(), pts.end(), y_less);
	}
	int find(int p) {
		return lower_bound(pts.begin(), pts.end(), p, y_less) - pts.begin();
	}
	void add(int p) {
		for (int i = find(p); i < pts.size(); i += (i+1) & -(i+1)) ++cnt[i];
	}
	int get(int p) {
		int res = 0;
		for (int i = find(p)-1; i >= 0; i -= (i+1) & -(i+1)) res += cnt[i];
		return res;
	}
};

bit *T[200000];
int pts[200000];

void init() {
	for (int i = 0; i < n; ++i) pts[i] = i;
	sort(pts, pts+n, x_less);
	for (int e = 1; e <= n; ++e) T[e-1] = new bit(pts + e - (e&-e), pts+e);
}

int find(int p) {
	return lower_bound(pts, pts+n, p, x_less) - pts;
}

void add(int p) {
	for (int i = find(p); i < n; i += (i+1) & -(i+1)) T[i]->add(p);
}

int get(int p) {
	int res = 0;
	for (int i = find(p)-1; i >= 0; i -= (i+1) & -(i+1)) res += T[i]->get(p);
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a+i);
	for (int i = 0; i < n; ++i) scanf("%d", x+i), bp[x[i]] = i;
	for (int i = 0; i < n; ++i) scanf("%d", y+i), cp[y[i]] = i;
	for (int i = 0; i < n; ++i) x[i] = bp[a[i]], y[i] = cp[a[i]];
	long long ans = 0;
	init();
	for (int i = 0; i < n; add(i), ans += get(i), ++i);
	printf("%lld\n", ans);
}
