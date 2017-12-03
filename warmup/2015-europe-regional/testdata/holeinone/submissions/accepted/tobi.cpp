#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define INTERSECTS(S,T,A,B) (ccw(A,B,S) * ccw(A,B,T) <= 0)
int N, coords[15][4], dup[15][4], hole[2], dupHole[2], orig[2], best = -1;
vector<int> perms, lastPerms;
double g[3], h[3];

int ccw(int* a, int *b, int *p) {
	int c = (b[0] - a[0]) * (p[1] - a[1]) - (p[0] - a[0]) * (b[1] - a[1]);
	return (c == 0 ? 0 : (c > 0) ? 1 : -1);
}
void getLine(int *p0, int *p1, double *l) {
	l[0] = p1[1]-p0[1], l[1] = p0[0]-p1[0];
	l[2] = l[0]*p0[0] + l[1]*p0[1];
}

void flip(int wall, int *data) {
	if (dup[wall][0] == dup[wall][2]) data[0] = 2*dup[wall][0] - data[0];
	else                              data[1] = 2*dup[wall][1] - data[1];
}

double getDist(int wall) { // computes distance to intersection of line segments (origin,hole) and wall
	if (INTERSECTS(orig, dupHole, dup[wall], dup[wall] + 2) && INTERSECTS(dup[wall], dup[wall] + 2, orig, dupHole)) {
		getLine(orig, dupHole, g);
		getLine(dup[wall], dup[wall] + 2, h);
		double det = g[0]*h[1] - h[0]*g[1], sx = g[2]*h[1] - h[2]*g[1], sy = g[0]*h[2] - h[0]*g[2];
		return sqrt(sx*sx + sy*sy) / abs(det);
	} else return -1;
}

void flippy(int allowed) { // compute score for given prefix
	FOR(i, 0, 2) dupHole[i] = hole[i];
	FOR(i, 0, N) FOR(j, 0, 4) dup[i][j] = coords[perms[i]][j];
	FOR(i, 0, allowed) { // flip hole at final location for this permutation
		flip(i, dupHole);
		FOR(j, i+1, N) FOR(k, 0, 2) flip(i, dup[j] + 2*k);
	}
	FOR(i, 0, N) FOR(j, 0, 4) dup[i][j] = coords[perms[i]][j];
	double lastDist = 0, distHole = sqrt(dupHole[0]*dupHole[0] + dupHole[1]*dupHole[1]);
	FOR(i, 0, allowed+1) { // for each wall in permutation: check if there is no *later* wall between the ball and the wall itself
		double flipDist = (i == allowed) ? distHole : getDist(i);
		if (flipDist < 0) return;
		FOR(j, 0, N) {
			if (i == j && i != allowed) continue;
			double lineDist = getDist(j);
			if (lineDist >= 0 && lastDist < lineDist && lineDist < flipDist) return;
		}
		lastDist = flipDist;
		FOR(j, i+1, N) FOR(k, 0, 2) flip(i, dup[j] + 2*k); // flip walls at current wall
	}
	best = max(best, allowed);
}

int main() {
	cin >> N >> hole[0] >> hole[1];
	FOR(i, 0, N) FOR(j, 0, 4) cin >> coords[i][j];
	FOR(i, 0, N) perms.push_back(i);
	FOR(i, 0, N) lastPerms.push_back(-1);

	flippy(0); // direct connection
	do { // try each permutation
		int firstDiff = N;
		FOR(i, 0, N) if (lastPerms[N-1-i] != perms[N-1-i]) {
			firstDiff = N-1-i;
			lastPerms[N-1-i] = perms[N-1-i];
		}
		FOR(i, firstDiff, N) flippy(i+1); // try each prefix (once)
	} while (next_permutation(perms.begin(), perms.end()));
	if (best < 0) cout << "impossible" << endl;
	else cout << best << endl;

	return 0;
}
