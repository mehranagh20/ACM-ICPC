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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

ll sieve_size;
bitset<10010010> bs;
vector<ll> primes;
void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
    ios::sync_with_stdio(0);
    sieve(10000000 + 1000);
    ll tc; cin >> tc;
    vector<ll> two;
    for(int i = 1; i < primes.size(); i++) {
        if(!bs[primes[i] + 2]) two.push_back(primes[i] + 2);
    }

    while(tc--) {
        ll ans = 0;
        ll n, k; cin >> n >> k;
        vector<ll>::iterator it = lower_bound(primes.begin(), primes.end(), n);
        if(*it > n) it--;
        int s = 0;
        ans = it - primes.begin() + 1;
        ans = min(ans, k);
        s = k - ans;
        for(int i = 2; i <= n && s; i += 2) if(!bs[i])
            ans += 2, s--;
        if(s) {
            it = lower_bound(two.begin(), two.end(), n);
            if (*it > n) it--;
            int all = it - two.begin() + 1;
            if(all > s) {
                ans += s * 2;
            }
            else {
                ans += all * 2;
                s -= all;
                ans += s * 3;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
