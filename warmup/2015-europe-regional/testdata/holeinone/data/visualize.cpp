#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;

#define xx first
#define yy second

const int maxN = 10;

int n, alpha, beta;
int p[maxN+1];
pii s, t, w1[maxN+1], w2[maxN+1];
pdd r[maxN+2];

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
int cast_ray(int k, bool calc_intersections = false) {
	pii vs = s, vt = t;
	for (int i = k-1; i >= 0; i--) vt = reflect(vt, p[i]);
	if (vs == vt) return -1;
	int tcur = 0;
	for (int i = 0; i <= k; i++) {
		pii v(vt.xx-vs.xx, vt.yy-vs.yy);
		int ti = intersection_time(vs, v, p[i]);
		if (ti < tcur) return -1;
		for (int j = i+1; j <= n; j++) {
			int tj = intersection_time(vs, v, p[j]);
			if (tj >= tcur && tj < ti && p[j] != n) return -1;
		}
		if (calc_intersections) {
			double dt = ti - tcur;
			if (v.xx) dt /= abs(v.xx);
			if (v.yy) dt /= abs(v.yy);
			r[i+1].xx = r[i].xx + v.xx*dt;
			r[i+1].yy = r[i].yy + v.yy*dt;
		}
		tcur = ti;
		vs = reflect(vs, p[i]);
		vt = reflect(vt, p[i]);
	}
	return k;
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
	vector<int> q = {-1};
	do {
		for (int k = 0; k <= n; k++) {
			if (p[k] == n && is_sorted(p+k+1,p+n+1)) {
				int cur = cast_ray(k);
				if (cur > best) {
					best = cur;
					q = vector<int>(p,p+n+1);
				}
			}
		}
	} while (next_permutation(p,p+n+1));
	
	int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
	for (int i = 0; i <= n; i++) {
		xmin = min(xmin, w1[i].xx);
		xmax = max(xmax, w2[i].xx);
		ymin = min(ymin, w1[i].yy);
		ymax = max(ymax, w2[i].yy);
	}
	
	int margin = 50;

	xmax -= xmin, ymax -= ymin;
	assert(xmax || ymax);
	double scale = 924.0/max(xmax,ymax);
	xmax *= scale, ymax *= scale;
	xmax += 2*margin, ymax += 2*margin;

	auto move = [&](double x, double y) {
		pdd q(x,y);
		q.xx -= xmin, q.yy -= ymin;
		q.xx *= scale, q.yy *= scale;
		q.xx += margin, q.yy += margin;
		q.yy = ymax - q.yy;
		return q;
	};
	
	pdd S = move(s.xx,s.yy), T = move(t.xx,t.yy);
	vector<pdd> W1(n+1), W2(n+1);
	for (int i = 0; i <= n; i++)
		W1[i] = move(w1[i].xx,w1[i].yy), W2[i] = move(w2[i].xx,w2[i].yy);

	printf("<svg height=\"%d\" width=\"%d\">\n",ymax,xmax);

	int k = 0;
	if (q[0] != -1) while (q[k] != n) k++;
	if (best >= 0) {
		for (int i = 0; i <= n; i++) p[i] = q[i];
		cast_ray(k,true);
		for (int i = 0; i <= k+1; i++) r[i] = move(r[i].xx,r[i].yy);
		
		for (int i = 0; i <= k; i++) {
			printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" ",
				r[i].xx,r[i].yy,r[i+1].xx,r[i+1].yy);
			printf("style=\"stroke:green;stroke-width:3.5\" />\n");
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" ",
			W1[i].xx,W1[i].yy,W2[i].xx,W2[i].yy);
		printf("style=\"stroke:red;stroke-width:3.5\" />\n");
	}
	
	printf("<circle cx=\"%f\" cy=\"%f\" r=\"10\" fill=\"blue\" />\n",S.xx,S.yy);
	printf("<text x=\"%f\" y=\"%f\" fill=\"black\" ",S.xx,S.yy);
	printf("font-size=\"20\" ");
	printf("transform=\"translate(-22,-12)\">Ball</text>\n");
	printf("<circle cx=\"%f\" cy=\"%f\" r=\"10\" fill=\"blue\" />\n",T.xx,T.yy);
	printf("<text x=\"%f\" y=\"%f\" fill=\"black\" ",T.xx,T.yy);
	printf("font-size=\"20\" ");
	printf("transform=\"translate(-22,-12)\">Hole</text>\n");
	
	if (best >= 0) {
		for (int i = 1; i <= k; i++) {
			printf("<text x=\"%f\" y=\"%f\" fill=\"black\" ",r[i].xx,r[i].yy);
			printf("font-size=\"20\" ");
			printf("transform=\"translate(-20,-10)\">%d</text>\n",i);
		}
	}

	printf("</svg>\n");
}

