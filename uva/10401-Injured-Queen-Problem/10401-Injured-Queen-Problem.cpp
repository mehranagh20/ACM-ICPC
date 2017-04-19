//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
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
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int n;
vector<vector<llu>> memo;

llu sol(int i, vi &cols) {
    if(i == n) return 1;
    if(cols[i - 1] >= n) return 0;
    if(memo[i][cols[i - 1]] != inf) return memo[i][cols[i - 1]];
    memo[i][cols[i - 1]] = 0;
    llu ans = 0;
    if(cols[i] == -2) {
        int bef = cols[i - 1];
        for(int j = 0; j < n ; j++) if(abs(j - bef) >= 2) {
                cols[i] = j;
                ans += sol(i + 1, cols);
                cols[i] = -2;
            }
        return memo[i][cols[i - 1]] = ans;
    }
    else {
        if(abs(cols[i] - cols[i - 1]) < 2 || cols[i] >= n || cols[i - 1] >= n || cols[i] < 0) return 0;
        ans = sol(i + 1, cols);
        return memo[i][cols[i - 1]] = ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    string str;
    while(cin >> str) {
        llu ans = 0;
        n = str.size();
        vector<int> cols;
        for(auto &e : str) {
            if(isdigit(e)) cols.push_back(e - '0' - 1);
            else if(e != '?') cols.push_back(e - 56);
            else cols.push_back(-2);
        }
        memo.clear(); memo.resize(n, vector<llu>(n, inf));
        if(str[0] == '?') {
            for(int i = 0; i < n; i++) {
                cols[0] = i;
                ans += sol(1, cols);
            }
            cout << ans << endl;
        }
        else cout << sol(1, cols) << endl;
    }

    return 0;
}