//In The Name Of God
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

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
            if(factors.size() == 0)
                factors.push_back(ii(PF, 1));

            else if(factors.back().first == PF)
                factors.back().second++;

            else factors.push_back(ii(PF, 1));
            n /= PF;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(ii(n, 1)); // special case if n is a prime
}

int main() {
    ios::sync_with_stdio(0);
    int n, b;
    sieve(1001000);
    while(cin >> n >> b){
        double num = 0;
        for (int i = 1; i <= n; ++i)
            num += (log10(i) / log10(b));
        vii factors;
        primeFactors(b, factors);

        ll trail = inf;
        for(auto &i : factors){
            ll p = i.first, sum = 0;
            while(n / p){
                sum += n / p;
                p *= i.first;
            }
            trail = min(trail, sum / i.second);
        }

        cout << trail << ' ' << (int)num + 1 << endl;
    }

    return 0;
}
