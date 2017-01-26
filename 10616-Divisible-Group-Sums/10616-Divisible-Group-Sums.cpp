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

vvvi memo;
vi nums;
int m, d;

int sol(int tillNow, int ind, long long sum) {
    int mod = ((sum % d) + d) % d;

    if(tillNow == m) return (mod == 0 ? 1 : 0);
    if(memo[tillNow][mod][ind + 1] != -inf) return memo[tillNow][mod][ind + 1];
    memo[tillNow][mod][ind + 1] = 0;
    for(int i = ind + 1; i < nums.size(); i++) {
        memo[tillNow][mod][ind + 1] += sol(tillNow + 1, i, sum + nums[i]);
        //memo[tillNow][mod] += sol(tillNow + 1, mod, i, sum);
    }
    return memo[tillNow][mod][ind + 1];
 }

int main() {
    ios::sync_with_stdio(0);
    int tc = 0, n, q;
    while(cin >> n >> q && (n || q)) {
        nums.clear(); nums.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        cout << "SET " << ++tc << ":\n";
        for(int i = 0; i < q; i++) {
            cin >> d >> m;
            memo.clear(); memo.resize(m + 2, vvi(d + 1, vi(nums.size() + 1, -inf)));
            cout << "QUERY " << i + 1 << ": " << sol(0, -1, 0) << endl;
        }
    }
    return 0;
}