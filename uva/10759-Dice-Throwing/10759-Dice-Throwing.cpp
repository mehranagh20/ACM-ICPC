//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ull> vi;
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

ull x, n;
vvi memo;

ull gcd(ull a, ull b) {
    return a == 0 ? b : gcd(b % a, a);
}

ull solve(int id, ull score) {
    score = min(score, x);
    if(id == n) return score >= x ? 1 : 0;
    ull &ans = memo[id][score];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 1; i <= 6; i++) ans += solve(id + 1, score + i);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> x && (n || x)) {
        ull all = pow(6, n);
        memo.assign(n, vi(x + 10, -1));
        ull ans = solve(0, 0), f = gcd(ans, all);
        ans /= f, all /= f;
        if(!ans) cout << 0 << endl;
        else if(all == 1) cout << ans << endl;
        else cout << ans << "/" << all << endl;


    }

    return 0;
}
