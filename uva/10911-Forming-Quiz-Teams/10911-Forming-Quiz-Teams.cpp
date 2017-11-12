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

vii coors;
vd memo;
int n;

double solve(int bm) {
    if(bm == (1 << 2 * n) - 1) return 0;
    double &ans = memo[bm];
    if(ans != inf) return ans;
    int i;
    for(i = 0; i < 2 * n; i++) if(!(bm & (1 << i)))
        break;
    bm |= (1 << i);
    for(int j = 0; j < 2 * n; j++) if(!(bm & (1 << j)))
        ans = min(ans, solve(bm | (1 << j)) + sqrt(pow(coors[i].first - coors[j].first, 2) + pow(coors[i].second - coors[j].second, 2)));
    return ans;
}

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    string str;
    int tc = 1;
    while(cin >> n && n) {
        coors.assign(2 * n, ii(0, 0));
        for(auto &e: coors) cin >> str >> e.first >> e.second;
        memo.assign(1 << (2 * n + 1), inf);
        cout << "Case " << tc++ << ": " << fixed << setprecision(2) << solve(0) << endl;
    }


    return 0;
}
