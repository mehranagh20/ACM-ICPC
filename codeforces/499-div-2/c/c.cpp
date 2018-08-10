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
typedef vector<int> vi;
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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back


int n, m;
vi as, bs;

bool pos(double f) {
    double ms = (m + f) / as[0];
    if(f - ms < eps) return false;
    f -= ms;

    for(int i = 1; i < n; i++) {
        double ms = (m + f) / bs[i];
        if(f - ms < eps) return false;
        f -= ms;
        ms = (m + f) / as[i];
        if(f - ms < eps) return false;
        f -= ms;
    }
    ms = (m + f) / bs[0];
    if(f - ms < eps) return false;

    return true;

}

int const MX = 1e4;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    forn(i, n) {
        int tmp; cin >> tmp;
        as.push_back(tmp);
    }
    forn(i, n) {
        int tmp; cin >> tmp;
        bs.push_back(tmp);
    }

    double a = 0, b = 1e9 + 100;
    bool po = false;
    forn(i, MX) {
        double mid = (a + b) / 2;
        if(pos(mid)) b = mid, po = true;
        else a = mid;
    }
    if(po) cout << fixed << setprecision(8) << b << endl;
    else cout << -1 << endl;

    return 0;
}