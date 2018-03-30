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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

vi co;
ll i, n, r, k;

ll calc(ll i) {
    if(i + r >= n) return n - 1;
    return i + r;
}

bool pos(ll m) {
    ll cur = 0, kk = k;
    vi cco = co;
    for(i = 0; i < r; i++) cur += co[i];

    ll mi = 0;

    for(ll i = 0; i < n; i++) {
        if(i - mi > r) {
            cur -= cco[mi];
            mi++;
        }
        if(i + r < n)
            cur += cco[i + r];

        if(cur < m) {
            ll tmp = (m - cur);
            kk -= tmp;
            cco[calc(i)] += tmp;
            cur += tmp;

            if(kk < 0) return false;
        }

    }

    return true;


}

int main() {
    scanf("%lld%lld%lld", &n, &r, &k);
    co.assign(n, 0);
    ll mx = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &co[i]);
        mx = max(mx, co[i]);
    }

    ll l = 0, h = 1e19;

    while(l <= h) {
        ll mid = (l + h) / 2;
        if(pos(mid)) l = mid + 1;
        else h = mid - 1;
    }

    printf("%lld\n", l - 1);

    return 0;
}

