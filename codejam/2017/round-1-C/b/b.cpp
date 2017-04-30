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

vi first, second;
vvvvi memo;

int solve(int time, int p, int amount, int who) {
    if(amount > 720) return inf;
    if(p == 0 && first[time]) return inf;
    if(p == 1 && second[time]) return inf;
    if(time == 1439) {
        if(amount == 720)
            return p == who ? 0 : 1;
        return inf;
    }
    int &ans = memo[who][time][p][amount];
    if(ans != -1) return ans;
    ans = min(solve(time + 1, p == 0 ? 1 : 0, amount + (p == 1 ? 1 : 0), who) + 1, solve(time + 1, p, amount + (p == 0 ? 1 : 0), who));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, m; cin >> n >> m;
        first.assign(1500, 0), second.assign(1500, 0);
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            for(int j = a; j < b; j++) first[j] = 1;
        }
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            for(int j = a; j < b; j++) second[j] = 1;
        }
        memo.assign(2, vvvi(1500, vvi(2, vi(1500, -1))));
        cout << "Case #" << i << ": ";
        cout << min(solve(0, 0, 1, 0), solve(0, 1, 0, 1)) << endl;
    }

    return 0;
}
