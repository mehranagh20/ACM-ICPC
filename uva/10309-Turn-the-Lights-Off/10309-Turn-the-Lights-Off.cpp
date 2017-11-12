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

int main() {
    ios::sync_with_stdio(0);
    vii moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {0, 0}};
    string str;
    while(cin >> str && str != "end") {
        int tmp_ans = 0;
        vs grid(10);
        for(auto &e: grid) cin >> e;
        for(int i = 0; i < (1 << 10); i++) {
            tmp_ans = 0;
            vs cur_grid = grid;
            for(int j = 0; j < 10; j++) if(i & (1 << j)) {
                tmp_ans++;
                int x = 0, y = j;
                for(auto &m: moves)
                    if(x + m.first >= 0 && x + m.first < 10 && y + m.second >= 0 && y + m.second < 10) {
                        auto &c = cur_grid[x + m.first][y + m.second];
                        c = (c == '#' ? 'O' : '#');
                    }
            }
            for(int i = 1; i < 10; i++) for(int j = 0; j < 10; j++)
                if(cur_grid[i - 1][j] == 'O') {
                    tmp_ans++;
                    int x = i, y = j;
                    for(auto &m: moves)
                        if(x + m.first >= 0 && x + m.first < 10 && y + m.second >= 0 && y + m.second < 10) {
                            auto &c = cur_grid[x + m.first][y + m.second];
                            c = (c == '#' ? 'O' : '#');
                        }
                }
            bool found = true;
            for(int i = 0; i < 10; i++) if(cur_grid[9][i] == 'O') {
                found = false;
                break;
            }
            if(found)
             break;
        }
        cout << str << " " << tmp_ans << endl;
    }


    return 0;
}
