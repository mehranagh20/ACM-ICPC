#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

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
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define inf 1000000000
#define eps 1e-9

#include <bitset>

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

vii primeFactors(ll n) {
    vii factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        if(n % PF == 0)
            factors.push_back(ii(PF, 0));
        while (n % PF == 0) {
            n /= PF;
            factors.back().second++;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(ii(n, 1)); // special case if n is a prime
    return factors;
}

int main() {
    ios::sync_with_stdio(0);
    int n, b;
    sieve(1e6);
    while(cin >> n >> b && (n || b)){
        vii PF = primeFactors(b);
        vll counts(PF.size(), 0);
        vvll f1(n+2, vll(PF.size(), 0));

        for (int i = 2; i < n+2; ++i) {
            for (int j = 0; j < PF.size(); ++j) {
                ll pf = PF[j].first;
                ll sum = 0, base = pf;
                while(base <= i){
                    sum += (i / base);
                    base *= pf;
                }
                f1[i][j] = f1[i-1][j] + sum;
            }
        }


        for (int i = 0; i < PF.size(); ++i) {
            ll sum = 0;
            for (int j = 0; j < n+1; ++j) {
                sum += f1[j][i];
            }
            counts[i] = sum;
        }


        ll ans = counts[0];
        for (int i = 0; i < PF.size(); ++i) {
            ans = min(ans, counts[i] / PF[i].second);
        }
        cout << ans << endl;
    }

    return 0;
}
