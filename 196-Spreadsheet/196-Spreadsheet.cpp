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

const int inf = 1000000000;
#define eps 1e-9;
vvi nums;
vector<vector<string>> expressions;

int solve(string &ex) {
    vii needs;
    int ans = 0;
    for(int i = 1; i < ex.size(); i++) {
        string tmp;
        while(!isdigit(ex[i])) tmp += ex[i++];
        int fN = 0, sN;
        for(int j = tmp.size() - 1; j >= 0; j--)
            fN += pow(26, (tmp.size() - 1 - j)) * (tmp[j] - 65);
        if(tmp.size() == 3) fN += 26 * 26 + 26; else if(tmp.size() == 2) fN += 26;
        tmp.clear(); while(isdigit(ex[i])) tmp += ex[i++];
        needs.push_back(make_pair(strtol(tmp.c_str(), NULL, NULL) - 1, fN));
    }
    for(auto &e : needs)
        ans += nums[e.first][e.second] == inf ? nums[e.first][e.second] = solve(expressions[e.first][e.second]) : nums[e.first][e.second];
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int m, n; cin >> n >> m;
        nums.clear(); nums.resize(m, vi(n, inf));
        expressions.clear(); expressions.resize(m, vector<string>(n));
        vii needCalc;
        string tmp;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
                cin >> tmp;
                if(tmp[0] == '=') {
                    needCalc.push_back(make_pair(i, j));
                    expressions[i][j] = tmp;
                }
                else nums[i][j] = strtol(tmp.c_str(), NULL, NULL);
            }
        for(auto &e : needCalc)
            nums[e.first][e.second] = solve(expressions[e.first][e.second]);
        for(int i = 0; i < m; i++) {
            cout << nums[i][0];
            for (int j = 1; j < n; j++) cout << " " << nums[i][j];
            cout << endl;
        }
    }
    return 0;
}