#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back
#define xx first
#define yy second

const double inf = 1e100;

ll n;
pll s, t;
struct wall {
	ll x1, y1, x2, y2;
};
vector<wall> walls;

double dist(pll a, pll b) {
	double dx = a.xx-b.xx, dy = a.yy-b.yy;
	return sqrt(dx*dx + dy*dy);
}

inline void reflect(pll &p, wall w) {
	if (w.x1 == w.x2) p.xx = 2*w.x1 - p.xx; else p.yy = 2*w.y1 - p.yy;
}

double intersection_time(pll p, pll v, wall w) {
	if (w.y1 == w.y2) swap(p.xx,p.yy), swap(v.xx,v.yy), swap(w.x1,w.y1), swap(w.x2,w.y2);
	if (!v.xx) return inf;
	double t = double(w.x1-p.xx)/v.xx;
	double y = p.yy + t*v.yy;
	if (y < w.y1 - eps || y > w.y2 + eps) return inf;
	return t;
}

ll cast(pll vt) {
	if (s == vt) return -1;
	double d = dist(s,vt);
	pll vs = s;
	ll res = -1; double tcur = 0;
	vb used(n);
	FOR(k,0,n+1) {
		pll v(vt.xx-vs.xx,vt.yy-vs.yy);
		ll i = -1; double ti = inf;
		FOR(j,0,n) if (!used[j]) {
			double tj = intersection_time(vs,v,walls[j]);
			if (tj > tcur + eps && tj < ti) i = j, ti = tj;
		}
		double tn = dist(vs,t)/d;
		if (abs(vs.xx + tn*v.xx - t.xx) < eps && abs(vs.yy + tn*v.yy - t.yy) < eps) {
			if (tn > tcur + eps && tn < ti) res = k;
		}
		if (ti == inf) break;
		used[i] = true;
		tcur = ti, reflect(vs,walls[i]), reflect(vt,walls[i]);
	}
	return res;
}

unordered_set<ll> gen(ll x0, vl xs) {
	ll k = sz(xs);
	unordered_set<ll> res;
	FOR(mask,0,1 << k) for (ll mask1 = mask; ; mask1 = (mask1-1) & mask) {
		ll mask2 = mask ^ mask1;
		ll x = 0;
		FOR(i,0,k) {
			if (mask1 & (1 << i)) x += 2*xs[i];
			if (mask2 & (1 << i)) x -= 2*xs[i];
		}
		if (__builtin_popcount(mask) % 2) x -= x0; else x += x0;
		res.insert(x);
		if (!mask1) break;
	}
	return res;
}

int main() {
	cin >> n;
	walls.resize(n);
	s = {0,0};
	cin >> t.xx >> t.yy;
	vl xs, ys;
	for (auto &w: walls) {
		cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
		if (w.x1 > w.x2) swap(w.x1,w.x2);
		if (w.y1 > w.y2) swap(w.y1,w.y2);
		if (w.x1 == w.x2) xs.pb(w.x1); else ys.pb(w.y1);
	}
	ll res = -1;
	
	unordered_set<ll> vxs = gen(t.xx,xs), vys = gen(t.yy,ys);
	for (ll x: vxs) for (ll y: vys) res = max(res,cast({x,y}));
	
	if (res < 0) cout << "impossible" << endl;
	else cout << res << endl;
}

