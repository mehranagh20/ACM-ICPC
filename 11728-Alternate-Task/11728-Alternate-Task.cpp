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

ll sumDiv(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= n) {
        ll power = 0;
        while (n % PF == 0) {
            n /= PF;
            power++;
        }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (n != 1) ans *= ((ll)pow((double)n, 2.0) - 1) / (n - 1);  // last
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    sieve(1010);
    int tc = 1, n;
    while(cin >> n && n) {
        int ans = -1;
        for(int i = 1; i < 1000; i++) if(sumDiv(i) == n)
            ans = i;
        cout << "Case " << tc++ << ": " << ans << endl;
    }

    return 0;
}
