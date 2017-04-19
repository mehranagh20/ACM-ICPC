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

void primeFactors(ll n, vii &factors) {
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            if(factors.size() == 0) {
                n /= PF;
                factors.push_back(ii(PF, 1));
                continue;
            }
            n /= PF;
            if(factors.back().first == PF) factors.back().second++;
            else factors.push_back(ii(PF, 1));
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(ii(n, 1)); // special case if n is a prime
}

int main() {
    ios::sync_with_stdio(0);
    sieve(1e5);
    ll n;
    while(cin >> n && n) {
        vii factors;
        ll ans = 1;
        primeFactors(n, factors);
        for(auto &e : factors) ans *= 2 * e.second + 1;
        cout << n << " " << (ans + 1) / 2 << endl;
    }

    return 0;
}
