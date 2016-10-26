#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vector<string> land;
vii hlp = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

int dfs(int r, int c, char cmp) {
    if(r >= land.size() || c >= land[0].size()) return 0;
    if(land[r][c] != cmp) return 0;
    int ans = 1;
    land[r][c] = cmp + 1;
    for(int i = 0; i < 8; i++) ans += dfs(r + hlp[i].first, c + hlp[i].second, cmp);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    vector<string> &tmp = land;
    int tc, blank = 0; cin >> tc;
    cin.get(); cin.get();
    string tmpStr;
    while(tc--) {
        if(blank++) cout << endl;
        land.clear();
        while(getline(cin, tmpStr) && !tmpStr.empty()) {
            if(tmpStr[0] == 'L' || tmpStr[0] == 'W')
                land.push_back(tmpStr);
            else {
                stringstream ss(tmpStr);
                int a, b; ss >> a >> b;
                cout << dfs(a - 1, b - 1, land[a - 1][b - 1]) << endl;
            }
        }
    }
    return 0;
}