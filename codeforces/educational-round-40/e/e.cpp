//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<ld, ld> dd;
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


int main() {
    ll n, t, tmp; cin >> n >> t;
    vdd at(n);
    for(auto &e: at) {
        cin >> tmp;
        e.second = tmp;
    }
    for(auto &e: at) {
        cin >> tmp;
        e.first = tmp;
    }

    ld totAm = 0, totT = 0;
    ll minT = inf, maxT = 0;
    for(auto &e: at) {
        totAm += e.second, totT += e.first * e.second;
        minT = min(minT, (ll)e.first), maxT = max(maxT, (ll)e.first);
    }

    ld temp = totT / totAm;
    sort(at.begin(), at.end());

    if(minT > t || maxT < t) {
        cout << 0 << endl;
        exit(0);
    }

    if(t > temp) {
        for(int i = 0; i < n; i++) {
            if(at[i].first - t == 0)
                break;
            ld need = max(((totAm - at[i].second) * t - (totT - at[i].first * at[i].second)) / (at[i].first - t), (ld)0.);
            totAm -= (at[i].second - need), totT -= (at[i].second - need) * at[i].first;
        }

    } else {
        for(int i = n - 1; i >= 0; i--) {
            if(at[i].first - t == 0)
                break;
            ld need = max(((totAm - at[i].second) * t - (totT - at[i].first * at[i].second)) / (at[i].first - t), (ld)0.);
            totAm -= (at[i].second - need), totT -= (at[i].second - need) * at[i].first;
        }
    }

    cout << fixed << setprecision(10) << totAm << endl;


    return 0;
}