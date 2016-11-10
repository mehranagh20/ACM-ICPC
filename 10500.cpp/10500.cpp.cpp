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
    neighbors.push_back(ii(0, -1));
    neighbors.push_back(ii(1, 0));
    neighbors.push_back(ii(0, 1));
    neighbors.push_back(ii(-1, 0));

    int n, m;
    while (cin >> n >> m && n && m) {
        int x, y; cin >> x >> y;
        x--; y--;
        vector<vector<char>> mp(n, vector<char>(m, '-'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mp[i][j];

        vvi seen(n, vi(m, 0)), visited(n, vi(m, 0));
        seen[x][y] = 1;
        bool stuck = false;
        int moves = 0;
        while (!stuck) {
            // cerr << x << ' ' << y << endl;
            moves++;
            visited[x][y] = 1;
            int newx = -1, newy = -1;
            for (int i = 0; i < neighbors.size(); i++) {
                ii nei = ii(x + neighbors[i].first, y + neighbors[i].second);
                if (nei.first >= 0 && nei.first < n && nei.second >= 0 && nei.second < m
                        && !visited[nei.first][nei.second]) {

                    seen[nei.first][nei.second] = 1;
                    if (mp[nei.first][nei.second] != 'X') {
                        newx = nei.first;
                        newy = nei.second;
                    }
                }
            }
            if (newx != -1 && newy != -1) {
                x = newx;
                y = newy;
            } else {
                stuck = true;
            }
        }

        cout << endl;

        cout << '|';
        for (int j = 0; j < m; j++)
            cout << "---|";
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << '|';
            for (int j = 0; j < m; j++) {
                if (seen[i][j])
                    cout << ' ' << mp[i][j] << " |";
                else
                    cout << " ? |";
            }
            cout << endl;

            cout << '|';
            for (int j = 0; j < m; j++)
                cout << "---|";
            cout << endl;
        }

        cout << endl << "NUMBER OF MOVEMENTS: " << moves - 1 << endl;
    }

	return 0;
}
