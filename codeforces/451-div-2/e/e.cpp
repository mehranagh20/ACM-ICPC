//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vi tmp(n);
    ll need = n / 2, have = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i];
        if(((ll)(sqrt(tmp[i]))) * ((ll)(sqrt(tmp[i]))) == tmp[i]) have++;
    }
    if(have > need) {
        vi cur;
        have -= need;
        for(auto &e: tmp) if(((ll)(sqrt(e))) * ((ll)(sqrt(e))) == e) {
                cur.push_back(e);
            }
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        ll ans = 0;
        for(int i = 0; i < have; i++) {
            if(cur[i] == 0) ans += 2;
            else ans++;
        }
        cout << ans << endl;
    }
    else {
        need -= have;
        vi best;
        for(auto &e: tmp) if(((ll)(sqrt(e))) * ((ll)(sqrt(e))) != e) {
                ll f = (ll)(sqrt(e)), s = (ll)(sqrt(e)) + 1;
                best.push_back((min(e - (f * f), (s * s) - e)));
            }
        sort(best.begin(), best.end());
        ll ans = 0;
        for(int i = 0; i < need; i++) ans += best[i];
        cout << ans << endl;
    }


    return 0;
}
