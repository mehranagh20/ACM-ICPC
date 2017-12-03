#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
	ll x, y;
	point(ll x=0, ll y=0): x(x), y(y) {}
	bool operator==(point p) { return x == p.x && y == p.y; }
	point operator-(point p) { return point(x-p.x, y-p.y); }
	ll cross(point p) { return x*p.y - y*p.x; }
};

bool isect(point P1, point P2, point Q1, point Q2) {
	ll d = (Q2-Q1).cross(P2-P1);
	if (!d) return P2 == Q2;
	double t = 1.0*(P2-P1).cross(Q1-P1)/d;
	double s = 1.0*(Q2-Q1).cross(Q1-P1)/d;
	return 0 <= t && t <= 1 && 0 <= s && s <= 1;
}

point wells[2000], endp[2000];
int W, P, start[2000], col[2000];
vector<int> adj[2000];

bool dfs(int u, int c) {
	if (col[u]) return col[u] == c;
	col[u] = c;
	for (int v: adj[u]) if (!dfs(v, -c)) return false;
	return true;
}

int main(void) {
	scanf("%d%d", &W, &P);
	for (int i = 1; i <= W; ++i)
		scanf("%lld%lld", &wells[i].x, &wells[i].y);
	for (int i = 0; i < P; ++i) {
		scanf("%d%lld%lld", start+i, &endp[i].x, &endp[i].y);
		col[i] = 0;
		for (int j = 0; j < i; ++j)
			if (start[i] != start[j] && isect(wells[start[i]], endp[i],
											  wells[start[j]], endp[j]))
				adj[i].push_back(j), adj[j].push_back(i);
	}
	bool ok = true;
	for (int i = 0; i < P; ++i)
		ok &= col[i] || dfs(i, 1);
	printf("%s\n", ok ? "possible" : "impossible");
}
