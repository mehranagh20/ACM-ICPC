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

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        ll n, k, num_odd = 0, num_even = 0, odd = 0, even = 0, step = 1; cin >> n >> k;
        if(n & 1) num_odd++, odd = n;
        else num_even++, even = n;
        while(1) {
            if(k - step <= 0) break;
            k -= step;
            ll f_n_odd = 0, f_n_even = 0, f_odd = 0, f_even = 0;
            if(num_odd) {
                ll tmp = odd / 2;
                if(tmp & 1) f_n_odd = num_odd * 2, f_odd = tmp;
                else f_n_even = num_odd * 2, f_even = tmp;
            }
            if(num_even) {
                ll tmp = even / 2;
                if(tmp & 1) f_odd = tmp, f_even = tmp - 1;
                else f_even = tmp, f_odd = tmp - 1;
                f_n_even += num_even, f_n_odd += num_even;
            }
            num_odd = f_n_odd, num_even = f_n_even, odd = f_odd, even = f_even;
            // cout << "num_odd = " << num_odd << "    num_even = " << num_even << "   odd = " << odd << "    even = " << even << endl;
            step *= 2;
        }
        cout << "Case #" << i << ": ";
        if(even > odd) {
            if(num_even >= k) cout << even / 2 << " " << even / 2 - 1 << endl;
            else cout << odd / 2 << " " << odd / 2 << endl;
        }
        else {
            if(num_odd >= k) cout << odd / 2 << " " << odd / 2 << endl;
            else cout << even / 2 << " " << even / 2 - 1 << endl;
        }

    }

    return 0;
}
