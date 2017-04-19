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

int n;
double p;
vector<vd> memo;
vd po;

double solve(int mx, int left) {
    if(!left) return mx;
    double &ans = memo[mx][left];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i < left; i++)
        ans += po[i] * solve(max(i, mx), left - i - 1) * (1 - p);
    ans += po[left] * max(mx, left);
    return ans;

}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> p && n) {
        po.assign(n + 1, 1);
        for(int i = 1; i <= n; i++) po[i] = po[i - 1] * p;
        memo.assign(n + 1, vd(n + 1, -1));
        cout << fixed << setprecision(10) << solve(0, n) << endl;
    }


    return 0;
}
