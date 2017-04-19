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
	bool first = true;
	while (t--) {
		int n, l; cin >> n >> l;
		vi ls(n, 0);
		for (int i = 0; i < n; i++)
			cin >> ls[i];
		sort(ls.begin(), ls.end());
		int mini = 0, maxi = n - 1;
		int ans = 0;
		while (mini < maxi) {
			if (ls[mini] + ls[maxi] <= l) {
				mini++;
				maxi--;
			} else
				maxi--;
			ans++;
		}
		if (mini == maxi)
			ans++;

		if (!first)
			cout << endl;
		first = false;
		cout << ans << endl;
	}

	return 0;
}
