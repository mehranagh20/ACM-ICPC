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

string str;
vvi memo;

int solve(int i, int j) {
    if(i > j) return 0;
    if(i == j) return 1;
    if(memo[i][j] != inf) return memo[i][j];
    if(str[i] == str[j]) memo[i][j] = solve(i + 1, j - 1) + 2;
    else
        memo[i][j] = max(solve(i + 1, j), solve(i, j - 1));
    return memo[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    cin.ignore(100, '\n');
    while(tc--) {
        getline(cin, str);
        memo.assign(str.size() + 1, vi(str.size() + 1, inf));
        cout << solve(0, str.size() - 1) << endl;
    }


    return 0;
}
