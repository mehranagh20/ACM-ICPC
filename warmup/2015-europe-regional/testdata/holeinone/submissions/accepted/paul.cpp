#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define xx first
#define yy second

const int maxN = 10;

int n;
int p[maxN+1];
pii s, t, w1[maxN+1], w2[maxN+1];

double dist(pii a, pii b) {
	double dx = a.xx - b.xx , dy = a.yy - b.yy;
	return sqrt(dx*dx + dy*dy);
}

// reflects a across the line spanned by the i-th wall
pii reflect(pii a, int i) {
	if (w1[i].xx == w2[i].xx) a.xx += 2*(w1[i].xx-a.xx);
	if (w1[i].yy == w2[i].yy) a.yy += 2*(w1[i].yy-a.yy);
	return a;
}

int sgn(int x) { return (x > 0) - (x < 0); }

// returns the intersection time of the ray a+t*v with the i-th wall
int intersection_time(pii a, pii v, int i) {
	if (!v.xx) {
		if (w1[i].yy != w2[i].yy || a.xx < w1[i].xx || a.xx > w2[i].xx) return -1;
		return (w1[i].yy-a.yy)*sgn(v.yy);
	} else if (!v.yy) {
		if (w1[i].xx != w2[i].xx || a.yy < w1[i].yy || a.yy > w2[i].yy) return -1;
		return (w1[i].xx-a.xx)*sgn(v.xx);
	} else if (w1[i].xx == w2[i].xx) {
		int t  = (w1[i].xx-a.xx)*sgn(v.xx)*abs(v.yy);
		int t1 = (w1[i].yy-a.yy)*sgn(v.yy)*abs(v.xx);
		int t2 = (w2[i].yy-a.yy)*sgn(v.yy)*abs(v.xx);
		if (t2 < t1) swap(t1, t2);
		return (t >= t1 && t <= t2) ? t : -1;
	} else {
		int t  = (w1[i].yy-a.yy)*sgn(v.yy)*abs(v.xx);
		int t1 = (w1[i].xx-a.xx)*sgn(v.xx)*abs(v.yy);
		int t2 = (w2[i].xx-a.xx)*sgn(v.xx)*abs(v.yy);
		if (t2 < t1) swap(t1, t2);
		return (t >= t1 && t <= t2) ? t : -1;
	}
}

// returns true if there is a way to bounce off walls 
// p[0] to p[k-1] in order and arrive at t
bool cast_ray(int k) {
	pii vs = s, vt = t;
	for (int i = k-1; i >= 0; i--) vt = reflect(vt, p[i]);
	if (vs == vt) return false;
	int tcur = 0;
	for (int i = 0; i <= k; i++) {
		pii v(vt.xx-vs.xx, vt.yy-vs.yy);
		int ti = intersection_time(vs, v, p[i]);
		if (ti < tcur) return false;
		for (int j = i+1; j <= n; j++) {
			int tj = intersection_time(vs, v, p[j]);
			if (tj >= tcur && tj < ti && p[j] != n) return false;
		}
		tcur = ti;
		vs = reflect(vs, p[i]);
		vt = reflect(vt, p[i]);
	}
	return true;
}

int main() {
	cin >> n;
	s = {0,0};
	cin >> t.xx >> t.yy;
	for (int i = 0; i < n; i++) {
		cin >> w1[i].xx >> w1[i].yy >> w2[i].xx >> w2[i].yy;
		if (w1[i] > w2[i]) swap(w1[i], w2[i]);
	}
	w1[n] = w2[n] = t;

	iota(p,p+n+1,0);
	int best = -1;
	do {
		for (int k = 0; k <= n; k++) {
			if (p[k] == n && is_sorted(p+k+1,p+n+1)) {
				if (cast_ray(k)) best = max(best,k);
			}
		}
	} while (next_permutation(p,p+n+1));

	if (best < 0) cout << "impossible" << endl;
	else cout << best << endl;

}
