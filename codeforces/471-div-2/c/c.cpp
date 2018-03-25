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
typedef set<ll> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

ll sqr(ll x) {
    ll sq = sqrt((ld)x);
    while(sq * sq < x) sq++;
    while(sq * sq > x) sq--;
    return sq;
}

int main() {
    ull mx = 1e18;
    si nms;
    for(ull i = 2; i <= 1e6; i++)
        for(ull j = i * i * i; j <= mx; j *= i) {
            nms.insert(j);
            if(mx / i < j) break;
        }
    vi nums;
    for(auto &e: nms) {
        ll sq = sqr(e);
        if(sq * sq != e)
            nums.push_back(e);
    }

    ll q, l, r; scanf("%lld", &q);
    while(q--) {
        scanf("%lld%lld", &l, &r);
        ll two = sqr(r) - sqr(l - 1);
        ll oth = upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l);
        printf("%lld\n", two + oth);
    }


    return 0;
}