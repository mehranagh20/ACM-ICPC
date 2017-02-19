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

#define inf 1000000000
#define eps 1e-9

vi mv = {0, 1, 2, 3};
vector<vector<char>> grid;
ii ans;

bool won(int x, int y, char check) {
    int r = 0, c = 0, d1 = 0, d2 = 0;
    for(int i = 0; i < 4; i++)
        c += (grid[x][i] == check), r += (grid[i][y] == check), d1 += (grid[i][i] == check), d2 += (grid[i][3 - i] == check);
        return (c == 4 || r == 4 || d1 == 4 || d2 == 4);
}

bool solve(int id) {
    if(id % 2 == 0) {
        for(auto &e1 : mv) for(auto &e2 : mv)
            if(grid[e1][e2] == '.') {
                grid[e1][e2] = 'x';
                if(won(e1, e2, 'x')) {
                    grid[e1][e2] = '.';
                    ans = ii(e1, e2);
                    return true;
                }
                if(solve(id + 1)) {
                    grid[e1][e2] = '.';
                    ans = ii(e1, e2);
                    return true;
                }
                grid[e1][e2] = '.';
            }
    }
    else {
        bool has = false;
        for(auto &e1 : mv) for(auto &e2 : mv)
            if(grid[e1][e2] == '.') {
                has = true;
                grid[e1][e2] = 'o';
                if(won(e1, e2, 'o')) {
                    grid[e1][e2] = '.';
                    return false;
                }
                if(!solve(id + 1)) {
                    grid[e1][e2] = '.';
                    return false;
                }
                grid[e1][e2] = '.';
            }
        if(has) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    string s;
    while(getline(cin, s) && s == "?") {
        grid.assign(4, vector<char>(4, '.'));
        for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
            cin >> grid[i][j];
        cin.ignore();
        if(solve(0)) cout << "(" << ans.first << "," << ans.second << ")" << endl;
        else cout << "#####" << endl;
    }

    return 0;
}
