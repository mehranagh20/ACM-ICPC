#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
ll n, invs = 0;

void ms(vector<int>& vec) {
	ll len = vec.size();
	if (len <= 1) return;

	vector<int> left(vec.begin(), vec.begin() + len/2), right(vec.begin() + len/2, vec.end());
	ms(left), ms(right);

	int l = 0, r = 0, lS = left.size(), rS = right.size(), i = 0;
	while (l < lS && r < rS) {
		if (left[l] <= right[r]) vec[i++] = left[l++];
		else vec[i++] = right[r++], invs += (lS-l);
	}
	while (l < lS) vec[i++] = left[l++];
	while (r < rS) vec[i++] = right[r++];
}

int main() {
	cin >> n;
	vector<vector<int>> perms(3, vector<int>(n));
	vector<int> map(n), remapped(n);
	FOR(i, 0, 3) FOR(j, 0, n) cin >> perms[i][j];
	FOR(i, 0, 3) FOR(j, i + 1, 3) {
		FOR(k, 0, n) map[perms[i][k]-1] = k;
		FOR(k, 0, n) remapped[k] = map[perms[j][k]-1];
		ms(remapped);
	}
	cout << n*(n-1)/2 - invs/2 << endl;
	return 0;
}
