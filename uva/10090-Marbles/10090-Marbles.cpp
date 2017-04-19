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

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

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
    ll c, a, b, a1, b1;
    while(cin >> c && c) {
        cin >> a1 >> a >> b1 >> b;
        d = gcd(a, b);
        if(c % d != 0) cout << "failed\n";
        else {
            extendedEuclid(a, b);
            x *= c / d, y *= c / d, a /= d, b /= d;
            ll l = (int)ceil((-1.0 * x) / b), ans;
            ll u = (int)floor((y) / (double)a);
            ll f1 = x + l * b, s1 = y - l * a, f2 = x + u * b, s2 = y - u * a;
            ll cost1 = f1 * a1 + s1 * b1, cost2 = f2 * a1 + s2 * b1;
            if(cost1 < cost2) ans = l;
            else ans = u;
            if(u < l) cout << "failed\n";
            else cout << x + ans * b << " " << y - ans * a << endl;
        }
    }


    return 0;
}
