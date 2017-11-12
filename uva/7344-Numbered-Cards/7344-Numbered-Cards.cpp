//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

int n, MOD = 1000000007;
vvvi memo1;
int desmask, sz;
vvi lessSizes;
ll lsizes(int bitmask, int id, bool less) {
    if(id == sz) return bitmask == desmask;
    int dig = (int)(n / (pow(10, sz - id - 1))) % 10;
    ll &ans = memo1[bitmask][id][less];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i <= (less ? 9 : dig); i++) {
        if((1 << i) && desmask) {
            if(i == 0 && id = 0) continue;
            int now_bitmask = bitmask | (1 << i);
            less = (i == dig) && less;
            ans = (ans + lsizes(now_bitmask, id + 1, less)) % MOD;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc

    for(int i = 0; i < (1 << 9); i++) {
        int m = 0;
        for(int j = 0; j < 10; j++) m += (i & (1 << j));
        for(int l = 1; l < 10; l++) {
            ll val;
            if(i & 1) val = m - 1;
            else val = l;
            for(int j = l - 1; j >= l - m + 1; l--) val = (val * j) % MOD;
            val = (val * pow(m, l - m)) % MOD;
        }
    }

    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";


    }


    return 0;
}
