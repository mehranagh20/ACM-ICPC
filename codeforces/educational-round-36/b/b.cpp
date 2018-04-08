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

int n, p, l, r;
int solve(int p, int x, int y) {
    if(x == 1 && y == n) return 0;
    if(x == 1) return abs(y - p) + 1;
    if(y == n) return abs(x - p) + 1;
    return (abs(y - p) + 1 + abs(x - y) + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> p >> l >> r;
    int ans = inf;
    ans = min(solve(p, l, r), ans);
    ans = min(solve(p, r, l), ans);
    cout << ans << endl;


    return 0;
}