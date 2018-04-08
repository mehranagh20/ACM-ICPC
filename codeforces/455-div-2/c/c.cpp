//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vs s;
vvi memo;
ll solve(int l, int i) {
    if(i >= vs.size()) return 1;
    ll &ans = memo[l][i];
    if(ans != -1) return ans;
    ans = 0;
    if(s[i] == "f") {
        for(int i = 1; i )
    }
    for(int j = 1; j <= l + 1; j++)
        ans += solve(j, i + 1);
    return ans;

}


int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    s.assign(n, "");
    for(auto &e: s) cin >> e;
    num = 0;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == "s") {
            i++;
            continue;
        }
        else {
            num++;
            while(s[i] == "f") i++;
        }
    }
    memo.resize(num + 10, vi(num + 10, -1));
    cout << solve(1, 1) << endl;



    return 0;
}
