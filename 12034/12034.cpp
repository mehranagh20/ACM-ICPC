#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;
const int MOD = 10056;

vvi choose;

// int C(int n, int k) {
// 	if (choose[n][k])
// 		return choose[n][k];
// 	if (k == 0)
// 		return 1;
// 	if (k == 1)
// 		return n;
// 	if (n == 1)
// 		return 1;
// 	if (n == k)
// 		return 1;
// 	return choose[n][k] = (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
// }

vi mem;

int solve(int n) {
	if (mem[n])
		return mem[n];
	int result = 1;
	for (int i = 1; i < n; i++) {
		result += ((ll)choose[n][i] * solve(n - i)) % MOD;
		result %= MOD;
	}
	return mem[n] = result % MOD;
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	mem.resize(1001, 0);
	choose.resize(1001, vi(1001, 0));

	for (int i = 0; i < 1001; i++) {
		choose[i][0] = 1;
		choose[i][i] = 1;
	}

	for (int i = 1; i < 1001; i++)
		for (int j = 1; j < i; j++)
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;

	mem[1] = 1;
	for (int test = 1; test <= t; test++) {
		int n; cin >> n;
		cout << "Case " << test << ": " << solve(n) << endl;
	}

	return 0;
}
