#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define xx first
#define yy second

const int maxN = 10;

int n;
pii s, t, w1[maxN], w2[maxN];

bool on(pii p, pii a, pii b) {
	if (a.xx == b.xx) {
		return p.xx == a.xx && p.yy >= a.yy && p.yy <= b.yy;
	} else {
		return p.yy == a.yy && p.xx >= a.xx && p.xx <= b.xx;
	}
}

int ccw(pii a, pii b, pii c) {
	int res = (b.xx-a.xx)*(c.yy-a.yy) - (b.yy-a.yy)*(c.xx-a.xx);
	if (!res) return 0; else return res/abs(res);
}

int main() {
	cin >> n;
	s.xx = s.yy = 0;
	cin >> t.xx >> t.yy;
	for (int i = 0; i < n; i++) {
		cin >> w1[i].xx >> w1[i].yy >> w2[i].xx >> w2[i].yy;
		if (w1[i] > w2[i]) swap(w1[i], w2[i]);
	}
	
	for (int i = 0; i < n; i++) {
		// end points equal?
		if (w1[i] == w2[i]) return -1;
		// wall not axis-aligned?
		if (w1[i].xx != w2[i].xx && w1[i].yy != w2[i].yy) return -2;
		// source or target inside wall?
		if (on(s,w1[i],w2[i]) || on(t,w1[i],w2[i])) return -3;
		// wall lies on x-axis?
		if (!w1[i].xx && !w2[i].xx) return -4;
		// wall lies on y-axis?
		if (!w1[i].yy && !w2[i].yy) return -5;	
		for (int j = 0; j < n; j++) if (i != j) {
			// walls intersecting?
			if (on(w1[i],w1[j],w2[j]) || on(w2[i],w1[j],w2[j])) return -6;
			if (ccw(w1[i],w1[j],w2[j])*ccw(w2[i],w1[j],w2[j]) < 0 &&
				ccw(w1[j],w1[i],w2[i])*ccw(w2[j],w1[i],w2[i]) < 0) return -7;
		}
	}

	return 42;
}
