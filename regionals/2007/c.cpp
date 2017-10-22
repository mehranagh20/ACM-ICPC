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
int w, d, l;
double pw, pd, pl;
vector<vd> memo;
double solve(int n, int p) {
    if(p <= 0) return 1;
    if(n == 0) return 0;
    double &ans = memo[n][p];
    if(ans != -1) return ans;
    ans = 0;
    ans += (pw * solve(n - 1, p - 3));
    ans += (pd * solve(n - 1, p - 1));
    ans += (pl * solve(n - 1, p));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int n, p;
    while(cin >> n >> p && (n || p)) {
        cin >> w >> d >> l;
        pw = (double) w / (w + d + l);
        pd = (double) d / (w + d + l);
        pl = (double) l / (w + d + l);

        memo.assign(n + 10, vd(p + 1, -1));
        double ans = solve(n, p);
        cout << fixed << setprecision(1) << ans * 100 << endl;

    }


    return 0;
}
