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


#include <bitset>

ll sieve_size, l, r;
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

bool isPrime(ll n) {
    if (n <= sieve_size) return bs[n];
    for (ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0) return false;
    return true;
} // note: only work for n <= (last prime in vi "primes")^2

int main() {
    ios::sync_with_stdio(0);
    sieve(1e6);
    while(cin >> l >> r) {
        ll min1 = -inf, min2 = inf, max1 = 0, max2 = 0;
        ll bef = -1;
        for(; l <= r; l++) if(isPrime(l)) {
            if(bef == -1) {
                bef = l;
                continue;
            }
            if(l - bef < min2 - min1) min2 = l, min1 = bef;
            if(l - bef > max2 - max1) max2 = l, max1 = bef;
            bef = l;
        }
        if(max1 != 0) cout << min1 << "," << min2 << " are closest, "<< max1 << "," << max2 << " are most distant." << endl;
        else cout << "There are no adjacent primes.\n";
    }

    return 0;
}
