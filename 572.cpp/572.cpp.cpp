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

	vii neighbors;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			neighbors.push_back(ii(i, j));

	int m, n;
	while (cin >> m >> n && m) {
		vector<string> grid(m, "");
		for (int i = 0; i < m; i++)
			cin >> grid[i];
		int ans = 0;
		vvi visited(m, vi(n, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (visited[i][j] || grid[i][j] == '*') continue;
				ans++;
				stack<ii> s;
				s.push(ii(i, j));
				visited[i][j] = 1;
				while (!s.empty()) {
					ii v = s.top();
					s.pop();
					for (int k = 0; k < neighbors.size(); k++) {
						ii u = neighbors[k];
						u.first += v.first;
						u.second += v.second;
						if (u.first >= 0 && u.first < m && u.second >= 0 && u.second < n && !visited[u.first][u.second] && grid[u.first][u.second] == '@') {
							s.push(u);
							visited[u.first][u.second] = 1;
						}
					}
				}
			}
		cout << ans << endl;
	}

	return 0;
}
