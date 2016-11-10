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

	for (int test = 1; ; test++) {
		int n; cin >> n;
		if (n == 0)
			break;
		cout << "Game " << test << ':' << endl;
		vi s(n, 0);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		while (true) {
			vi tmp = s;
			vi g(n, 0);
			for (int i = 0; i < n; i++)
				cin >> g[i];
			if (g[0] == 0)
				break;
			int strong = 0;
			for (int i = 0; i < n; i++)
				if (tmp[i] == g[i]) {
					g[i] = tmp[i] = -1;
					strong++;
				}
			int weak = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (tmp[i] != -1 && tmp[i] == g[j]) {
						weak++;
						g[j] = tmp[i] = -1;
						break;
					}
			cout << "    (" << strong << ',' << weak << ')' << endl;
		}
	}

	return 0;
}
