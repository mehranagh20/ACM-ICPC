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

double up = sqrt(.75) * 2 / 3., down = sqrt(.75) * 1 / 3.;

int main() {
    ios::sync_with_stdio(0);
    ll a, b;
    while(cin >> a >> b) {
        if(a > b) swap(a, b);
        ll f = sqrt(a), s = sqrt(b);
        bool isfUp = (f % 2 == 0 && a % 2 == 0) || (f % 2 && a % 2), issUp =
                (s % 2 == 0 && b % 2 == 0) || (s % 2 && b % 2);
        a -= f * f + f, b -= s * s + s;
        if(f != s) {
            double hor = abs(a - b) * .5, ver = (isfUp ? down : up) + (issUp ? up : down);
            if (s - f) ver += (s - f - 1) * sqrt(.75);
            cout << setprecision(3) << fixed << sqrt(hor * hor + ver * ver) << endl;
        }
        else {
            if(!(isfUp ^ issUp)) cout << setprecision(3) << fixed << .5 * abs(a - b) << endl;
            else cout << setprecision(3) << fixed << sqrt((up - down) * (up - down) + (.5 * abs(a - b)) * (.5 * abs(a - b))) << endl;
        }
    }

    return 0;
}