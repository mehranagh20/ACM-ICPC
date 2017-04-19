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

int primeFactors(ll n) {
    //vi factors;
    ll PF_idx = 0, f = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        if(n % PF == 0) {
            f++;
            int k = 0;
            while (n % PF == 0) {
                k++;
                if(k >= 2) return 0;
                n /= PF;
                //factors.push_back(PF);
            }
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) f++; // special case if n is a prime
    return f % 2 == 0 ? 1 : -1;
    //return factors;
}

int main() {
    ios::sync_with_stdio(0);
    sieve(1e5);
    vi ans(1e6 + 10, 0);
    ans[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        int tmp = primeFactors(i);
        //cout << i << " " << tmp << " " << ans[i - 1] + tmp << endl;
        ans[i] = ans[i - 1] + tmp;
    }
    //cout << "done" << endl;
    int n;
    while(cin >> n && n) {
        cout << setw(8) << n << setw(8) << ans[n] - ans[n - 1] << setw(8) << ans[n] << endl;
    }


    return 0;
}
