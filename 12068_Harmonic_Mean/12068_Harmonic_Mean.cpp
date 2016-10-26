//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);

    int ts; cin >> ts;
    for (int t = 1; t <= ts; t++) {
        int n; cin >> n;
        vii v(n, ii(1, 0));
        ll den = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i].second;
            den *= v[i].second;
        }
        ll num = 0;
        for (int i = 0; i < n; i++) {
            v[i].first = den / v[i].second;
            num += v[i].first;
        }
        den *= n;
        ll g = gcd(num, den);
        cout << "Case " << t << ": " << den / g << '/' << num / g << endl;
    }

    return 0;
}