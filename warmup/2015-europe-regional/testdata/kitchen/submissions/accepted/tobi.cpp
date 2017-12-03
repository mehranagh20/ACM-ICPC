#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
int R, S, M, D, N, K[80], B[1005], I[80][1005], l, r;
bool incompat[80][80];

bool mult(ll &prod, ll factor) {
	ll neu = prod * factor;
	if (neu / factor == prod) {
		prod = neu;
		return true;
	}
	return false;
}

int main() {
	cin >> R >> S >> M >> D >> N;
	FOR(i, 0, R) cin >> B[i];
	FOR(i, 0, S+M+D) {
		cin >> K[i];
		FOR(j, 0, K[i]) cin >> I[i][j];
	}
	FOR(i, 0, N) {
		cin >> l >> r;
		incompat[l-1][r-1] = incompat[r-1][l-1] = true;
	}
	ll ret = 0;
	bool overflow = false;
	FOR(i, 0, S) FOR(j, S, S+M) FOR(k, S+M, S+M+D) {
		if (incompat[i][j] || incompat[j][k] || incompat[i][k]) continue;
		map<int,int> ings;
		int dishes[3] = {i, j, k};
		FOR(l, 0, 3) FOR(m, 0, K[dishes[l]]) ings[I[dishes[l]][m]] = 1;
		ll tmp = 1;
		for (auto it : ings) {
			if (!mult(tmp, B[it.first-1])) overflow = true;
			if (tmp > 1e18L) overflow = true;
		}
		ret += tmp;
		if (ret > 1e18L) overflow = true;
	}
	if (overflow) cout << "too many" << endl;
	else cout << ret << endl;

	return 0;
}
