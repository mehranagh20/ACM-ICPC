#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		vvi factors(n + 1, vi(1000, 0));
		for (int i = 2; a > 1; i++)
			while (a % i == 0) {
				factors[0][i]++;
				a /= i;
			}
		for (int i = 2; b > 1; i++)
			while (b % i == 0) {
				factors[1][i]++;
				b /= i;
			}

		for (int i = 2; i <= n; i++)
			for (int j = 2; j < 1000; j++)
				factors[i][j] = factors[i - 2][j] + factors[i - 1][j];

		for (int i = 2; i < 1000; i++) {
			if (factors[n][i])
				cout << i << ' ' << factors[n][i] << endl;
		}
		cout << endl;
	}

	return 0;
}
