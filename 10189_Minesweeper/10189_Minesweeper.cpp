//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

int main() {
    vii moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int n, m, tc = 0;
    while(cin >> n >> m && (n || m)) {
        if(tc++) cout << endl;
        vvi grid(n, vi(m, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
                char c; cin >> c;
                if(c == '*') {
                    grid[i][j] = -1;
                    for(auto &e : moves) if(i + e.first >= 0 && i + e.first < n && j + e.second >= 0 && j + e.second < m) if(grid[e.first + i][e.second + j] != -1)
                                grid[i + e.first][j + e.second]++;
                }
            }
        cout << "Field #" << tc << ":" << endl;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == -1) cout << '*';
                else cout << grid[i][j];
            }
            cout << endl;
        }
    }

}
