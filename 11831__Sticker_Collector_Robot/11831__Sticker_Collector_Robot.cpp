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

char grid[101][101], curr, ri[200], le[200];
int r, c, n, m, s;
map<char, ii> mp;

int forward() {
    int tmpR = r + mp[curr].first, tmpC = c + mp[curr].second;
    if(tmpR >= m || tmpR < 0 || tmpC >= n || tmpC < 0 || grid[tmpR][tmpC] == '#') return 0;
    r = tmpR; c = tmpC;
    if(grid[r][c] == '*') {
        grid[r][c] = '.';
        return 1;
    }
    return 0;
}

int main() {
    ri['N'] = 'L'; ri['S'] = 'O'; ri['L'] = 'S'; ri['O'] = 'N';
    le['N'] = 'O'; le['S'] = 'L'; le['O'] = 'S'; le['L'] = 'N';
    mp = {{'N', {-1, 0}}, {'S', {1, 0}}, {'L', {0, 1}}, {'O', {0, -1}}};
    while(cin >> m >> n >> s && (m || n || s)) {
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                char &tmp = grid[i][j];
                if(tmp == 'N' || tmp == 'S' || tmp == 'O' || tmp == 'L') {
                    curr = tmp;
                    r = i; c = j;
                }
            }
        char tmp;
        int ans = 0;
        for(int i = 0; i < s; i++) {
            cin >> tmp;
            if(tmp == 'D') curr = ri[curr];
            else if(tmp == 'E') curr = le[curr];
            else ans += forward();
        }
        cout << ans << endl;
    }

    return 0;
}