#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const double oo = 1e30;
const double eps = 1e-10;

struct point {
	double x, y;
	point(double x=0, double y=0): x(x), y(y) {}
	bool operator==(point p) { return x == p.x && y == p.y; }
	point operator-(point p) { return point(x-p.x, y-p.y); }
	point operator+(point p) { return point(x+p.x, y+p.y); }
	point operator*(double c) { return point(c*x, c*y); }
	point reflect(point A, point B) {
		point v = A + (B-A) * ((*this-A).dot(B-A)/(B-A).dist2());
		return v*2 - *this;
	}
	double dist2() { return x*x+y*y; }
	double cross(point p) { return x*p.y - y*p.x; }
	double dot(point p) { return x*p.x + y*p.y; }
};

double isect(point P1, point P2, point Q1, point Q2) {
	double d = (Q2-Q1).cross(P2-P1);
	if (fabs(d) < eps) return oo;
	double t = 1.0*(P2-P1).cross(Q1-P1)/d;
	double s = 1.0*(Q2-Q1).cross(Q1-P1)/d;
	return (-eps <= t && t <= 1+eps && eps <= s && s <= 1) ? s : oo;
}

int n;
point hole;
vector<point> W;
int opt = -1;

void reflect(vector<point> &P, point A, point B) {
	for (auto &p: P) p = p.reflect(A, B);
}

void score(vi &hits) {
	point goal = hole, at;
	auto RW = W;
	for (int h: hits) {
		goal = goal.reflect(RW[2*h], RW[2*h+1]);
		reflect(RW, RW[2*h], RW[2*h+1]);
	}
	RW = W;
	vi used(n, false);
	for (int i = 0; i <= hits.size(); ++i) {
		double htime = oo;
		int hwall = -1;
		for (int w = 0; w < n; ++w) {
			if (used[w]) continue;
			double t = isect(at, goal, RW[2*w], RW[2*w+1]);
			if (t < htime) htime = t, hwall = w;
		}
		if (hwall != (i < hits.size() ? hits[i] : -1)) return;
		if (i < hits.size()) {
			used[hwall] = true;
			at = at + (goal-at)*(htime+eps);
			reflect(RW, RW[2*hwall], RW[2*hwall+1]);
		}
	}
	opt = max(opt, (int)hits.size());
}

void go(vi &hits) {
	score(hits);
	for (int i = 0; i < n; ++i)
		if (find(hits.begin(), hits.end(), i) == hits.end()) {
			hits.push_back(i);
			go(hits);
			hits.pop_back();
		}
}

int main(void) {
	scanf("%d", &n);
	W.resize(2*n);
	scanf("%lf%lf", &hole.x, &hole.y);
	for (int i = 0; i < n; ++i) 
		scanf("%lf%lf%lf%lf", &W[2*i].x, &W[2*i].y, &W[2*i+1].x, &W[2*i+1].y);
	vi hits;
	go(hits);
	if (opt < 0) printf("impossible\n");
	else printf("%d\n", opt);
}
