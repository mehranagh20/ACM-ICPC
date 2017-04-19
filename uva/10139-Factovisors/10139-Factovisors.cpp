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

#define inf 1000000000
#define eps 1e-9

ll sieve_size,fac;
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

bool primeFactors(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        if(n % PF == 0) {
            int need = 0;
            while (n % PF == 0)
                n /= PF, need++;
            ll k = 0;
            while(fac / PF) k += fac / PF, PF *= primes[PF_idx];
            if(need > k) return false;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1 && fac / n <= 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    ll m;
    sieve(1e6 * 3);
    while(cin >> fac >> m) {
        if(primeFactors(m)) cout << m << " divides " << fac << "!\n";
        else cout << m << " does not divide " << fac << "!\n";
    }

    return 0;
}
