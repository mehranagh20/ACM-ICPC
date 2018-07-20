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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back


bool up(ll x, ll n) {
    ll y = (x * 1000) / n;
    return y % 10 >= 5;
}

ll rnd(ll x, ll n) {
    if(up(x, n)) return (x * 100) / n + 1;
    return (x * 100) / n;
}


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    forn(i, tc) {
        set<ll> ups;
        set<ii> need;
        int n, l, rem, ans = 0; cin >> n >> l;
        rem = n;
        for(int j = 1; j <= n; j++) if(up(j, n))
                ups.insert(j);
        vi nms;
        forn(j, l) {
            ll a; cin >> a;
            if(up(a, n)) ans += rnd(a, n);
            else {
                auto best = ups.lower_bound(a);
                if(best != ups.end()) {
                    need.insert(ii(*best - a, nms.size()));
                    nms.push_back(a);
                } else ans += rnd(a, n);
            }
            rem -= a;
        }

        if(ups.size()) {
            int mn = *ups.begin();
            nms.push_back(0);
            need.insert(ii(mn, nms.size() - 1));
            while (need.size() && need.begin()->first <= mn && need.begin()->first <= rem) { // to change
                int j = need.begin()->second, am = need.begin()->first;
                if(need.begin()->second != nms.size() - 1)
                    need.erase(need.begin());
                ans += rnd(nms[j] + am, n);
                rem -= am;
            }
        }

        for(auto &e: need) ans += rnd(nms[e.second], n);
        if(rem) ans += rnd(rem, n);
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }


    return 0;
}