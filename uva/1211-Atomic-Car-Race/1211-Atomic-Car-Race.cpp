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

double b;
int n, r;
vd dis;
vi loc;
vd memo;

double solve(int c) {
    double &now = memo[c];
    if(now != -1) return now;
    now = inf;
    for(int i = c + 1; i < n; i++)
        now = min(now, solve(i) + dis[loc[i] - loc[c] - 1] + b);
    now = min(now, dis[loc[n] - loc[c] - 1]);
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n && n) {
        loc.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) cin >> loc[i];
        cin >> b;
        double v, e, f;
        cin >> r >> v >> e >> f;
        dis.assign(loc.back() + 10, 0);
        for(int i = 0; i <= loc.back() + 5; i++) {
            if(i < r) dis[i] = 1. / (v - f * (r - i));
            else dis[i] = 1. / (v - e * (i - r));
        }
        for(int i = 1; i <= loc.back() + 5; i++) dis[i] += dis[i - 1];
        memo.assign(n + 10, -1);
        cout << fixed << setprecision(4) << solve(0) << endl;
    }


    return 0;
}
