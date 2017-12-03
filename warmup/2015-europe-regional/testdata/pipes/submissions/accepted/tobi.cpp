#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define INTERSECTS(S,T,A,B) (ccw(A,B,S) * ccw(A,B,T) <= 0)
#define INTERSECTS2(S,T,A,B) (INTERSECTS(S,T,A,B) && INTERSECTS(A,B,S,T))
ll W, P, sources[1000][2], endp[1000][2], pipes[1000], color[1000];
vector<int> adjList[1000];

ll ccw(ll* a, ll *b, ll *p) {
	ll c = (b[0] - a[0]) * (p[1] - a[1]) - (p[0] - a[0]) * (b[1] - a[1]);
	return (c == 0 ? 0 : (c > 0) ? 1 : -1);
}

bool twoc(int pipe, int curCol) {
	if (color[pipe] != 0) return color[pipe] == curCol;
	color[pipe] = curCol;
	for (int next : adjList[pipe]) if (!twoc(next, -1*curCol)) return false;
	return true;
}

int main() {
	cin >> W >> P;
	FOR(i, 0, W) cin >> sources[i][0] >> sources[i][1];
	FOR(i, 0, P) cin >> pipes[i] >> endp[i][0] >> endp[i][1], pipes[i]--;

	FOR(i, 0, P) FOR(j, i+1, P) {
		if (pipes[i] != pipes[j] && INTERSECTS2(sources[pipes[i]], endp[i], sources[pipes[j]], endp[j])) {
			adjList[i].push_back(j);
			adjList[j].push_back(i);
		}
	}
	bool possible = true;
	FOR(i, 0, P) if (!color[i]) possible &= twoc(i,1);
	cout << (possible ? "possible" : "impossible") << endl;

	return 0;
}
