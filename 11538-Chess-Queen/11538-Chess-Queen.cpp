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

int main() {
    ios::sync_with_stdio(0);
    ll a, b;
    while(cin >> a >> b && (a || b)) {
        ll m = min(a, b);
        ll dig = ((m * (m - 1)) / 2) * (abs(a - b) + 1) + ((m - 2) * (m - 1) * (m)) / 3;
        ll oth = ((a * (a - 1)) / 2) * b + ((b * (b - 1)) / 2) * a;
        ll sum = dig * 2 + oth;
        cout << sum * 2 << endl;
    }

    return 0;
}
