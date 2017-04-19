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

ll x, y, d;

void extendedEuclid(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    } // base case
    extendedEuclid(b, a % b); // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        ll xx, yy;
        cin >> xx >> yy;
        ll b = ceil((double)xx / yy), a = xx / yy;
        extendedEuclid(a, b);
        cout << (xx / d) * x + (b / d) << " " << (xx / d) * y - (a / d) << endl;
        //  cout << (x * xx) / d << ' ' << (y * xx) / d << endl;

    }


    return 0;
}
