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

vvvi memo;
int sum, n;
vi choc;

int solve(int id, int f, int s) {
    if(id == n) return max(max(f, s), sum - f - s) - min(min(f, s), sum - f - s);
    int &now = memo[id][f][s];
    if(now != inf) return now;
    now = min(now, solve(id + 1, f + choc[id], s));
    now = min(now, solve(id + 1, f, s + choc[id]));
    now = min(now, solve(id + 1, f, s));
    return now;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> n;
        choc.assign(n, 0);
        sum = 0;
        for(auto &e: choc) {
            cin >> e;
            sum += e;
        }
        memo.assign(n + 1, vvi(sum + 1, vi(sum + 1, inf)));
        cout << "Case " << i << ": " << solve(0, 0, 0) << endl;
    }



    return 0;
}
