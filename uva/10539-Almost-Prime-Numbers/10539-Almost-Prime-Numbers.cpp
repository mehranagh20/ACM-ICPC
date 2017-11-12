//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

#define inf 1000000000
#define eps 1e-9

ll sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes;

 // create list of primes in [0..upperbound]
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
        // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    sieve(1e6 + 100);
    int n; cin >> n;
    for (size_t i = 0; i < n; i++) {
        ll l, h; cin >> l >> h;
        ll kk = 0, ans = 0;
        while(primes[kk] * primes[kk] <= h) {
            // if(primes[kk] * primes[kk] >= l) {
                ll f = (log(l) / log(primes[kk])), s = (log(h) / log(primes[kk]));
                if(pow(primes[kk], s + 1) <= h) s++;
                if(pow(primes[kk], f) < l) f++;
                if(f <= 1) f = 2;
                ans += s - f + 1;
            // }
            kk++;
            if(kk >= primes.size()) break;
        }
        cout << ans << endl;
    }



    return 0;
}
