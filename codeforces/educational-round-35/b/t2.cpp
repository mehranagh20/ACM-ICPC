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

	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = min(a, b); i > 0; i--) {
		if (a / i + b / i >= n) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}