//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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

#define inf 1000000000
#define eps 1e-9

vector<string> fild;
vii moves;
int n, m;

void fillWhites(int i, int j) {
    fild[i][j] = '2';
    for(auto &e : moves) {
        if (i + e.first >= m || j + e.second >= n || i + e.first < 0 || j + e.second < 0) continue;
        if (fild[i + e.first][j + e.second] == '0')
            fillWhites(i + e.first, j + e.second);
    }
}

int dfsBlack(int i, int j) {
    int holes = 0;
    fild[i][j] = '2';
    for(auto &e : moves) {
        if (i + e.first >= m || j + e.second >= n || i + e.first < 0 || j + e.second < 0) continue;
        if (fild[i + e.first][j + e.second] == '1')
            holes += dfsBlack(i + e.first, j + e.second);
        else if(fild[i + e.first][j + e.second] == '0') {
            holes++;
            fillWhites(i + e.first, j + e.second);
        }
    }
    return holes;
}

int main() {
    ios::sync_with_stdio(0);

    vector<string> &f = fild;

    vector<char> poss = {'W', 'A', 'K', 'J', 'S', 'D'};
    moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    string def[110];
    int i = 0, tc = 1;
    for(int c = '0'; c <= '9'; c++) {
        bitset<4> tmp(i++);
        def[c] = tmp.to_string();
    }
    for(int c = 'a'; c <= 'f'; c++) {
        bitset<4> tmp(i++);
        def[c] = tmp.to_string();
    }
    fild.resize(201);
    char c;
    while(cin >> m >> n && (n || m)) {
        for(int i = 0; i < m; i++) {
            string tmp;
            for (int j = 0; j < n; j++) {
                cin >> c; tmp += def[c];
            }
            fild[i] = tmp;
        }
        n *= 4;
        for(int i = 0; i < m; i++) {
            if(fild[i][0] == '0') fillWhites(i, 0);
            if(fild[i][n - 1] == '0') fillWhites(i, n - 1);
        }
            for(int i = 0; i < n; i++) {
                if(fild[0][i] == '0') fillWhites(0, i);
                if(fild[m - 1][i] == '0') fillWhites(m - 1, i);
            }
        string ans;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
                if (fild[i][j] == '1') {
                    int tmp = dfsBlack(i, j);
                    ans += poss[tmp];
                }
            }
        sort(ans.begin(), ans.end());
        cout << "Case " << tc++ << ": " << ans << endl;

    }

    return 0;
}