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

#define inf 10000000000000LL
#define eps 1e-14

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    ll n, m, t;
    while(cin >> n >> m >> t) {
        multiset<ll> ms;
        for(int i = 0; i < n; i++) {
            ll tmp; cin >> tmp;
            ms.insert(tmp);
        }
        ll mx = -inf, mn = inf, avg = 0;
        set<int> st;
        for(auto it = ms.begin(); it != ms.end(); it++) {
            ll now = 0;
            multiset<ll> tms = ms;
            auto itt = tms.lower_bound(*it);
            ll cur = *itt;
            while(tms.size()) {
                tms.erase(itt);
                now += t;
                if(!tms.size()) break;
                cur = (cur + t) % m;
                itt = tms.lower_bound(cur);
                if(itt == tms.end()) {
                    itt = tms.begin();
                    now += (m - cur) + *itt;
                    cur = *itt;
                }
                else {
                    now += (*itt - cur);
                    cur = *itt;
                }
            }
            ll bef;
            if(it == ms.begin()) {
//                cout << *ms.rbegin() << endl;
                bef = *it + (m - *ms.rbegin()) - 1;
            }
            else {
                auto tmp = it; tmp--;
                bef = *it - *tmp - 1;
            }
            mn = min(mn, now), mx = max(mx, now + bef);
            if(st.find(*it) == st.end())
                avg += (bef + 1) * now + (bef * (bef + 1)) / 2, st.insert(*it);
        }
        cout << mn << endl << mx << endl << avg / gcd(avg, m) << '/' << m / gcd(m, avg) << endl;


    }

    return 0;
}
