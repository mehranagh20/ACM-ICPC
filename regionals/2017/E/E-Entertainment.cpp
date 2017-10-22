//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9
vs grid;

vii nei = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int a, int b, char c) {
    if(!grid.size()) return;
    if(a >= grid.size() || b >= grid[a].size() || a < 0 || b < 0 || grid[a][b] != c) return;
    grid[a][b] = ' ';
    for(auto &e: nei) dfs(a + e.first, b + e.second, c);
}

int main() {
    ios::sync_with_stdio(0);
    int tc = 1;
    while(true) {
        if(cin.peek() == EOF) break;
        grid.clear();
        while(isalpha(cin.peek())) {
            string str; getline(cin, str);
            grid.push_back(str);
        }
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            string sss;
            getline(cin, sss);
            a--, b--;
            dfs(a, b, grid[a][b]);

            for(int i = 0; i < grid.size(); i++) {
                int k = -1;
                for(int j = 0; j < grid[i].size(); j++) if(grid[i][j] == ' ') {
                        k = j;
                        break;
                    }
                if(k != -1) {
                    for(int j = k + 1; j < grid[i].size(); j++) if(grid[i][j] != ' ') {
                            grid[i][k] = grid[i][j];
                            grid[i][j] = ' ';
                            k++;
                        }
                }
            }
            for(int i = 0; i < grid[0].size(); i++) {
                int k = -1;
                for(int j = grid.size() - 1; j >= 0; j--) if(grid[j][i] == ' ') {
                        k = j;
                        break;
                    }
                if(k != -1) {
                    for(int j = k - 1; j >= 0; j--) if(grid[j][i] != ' ') {
                            grid[k][i] = grid[j][i];
                            grid[j][i] = ' ';
                            k--;
                        }
                }
            }
            while(grid.size() && grid[0] == string(grid[0].size(), ' ')) grid.erase(grid.begin());
            while(grid.size()) {
                int j = grid[0].size() - 1;
                int found = true;
                for(int i = 0; i < grid.size(); i++) if(grid[i][j] != ' ') found = false;
                if(found) for(int i = 0; i < grid.size(); i++) grid[i].pop_back();
                else break;
            }
        }
        cout << "Test case #" << tc++ << ":\n";
        for(int i = 0; i < grid.size(); i++) {
            // cout << (grid[i].size()) << endl;
            cout << grid[i] << endl;
        }
    }


    return 0;
}
