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
bitset<1000000> bss;
vi primes;
vector<ll> hprimes, hnumbers;

 // create list of primes in [0..upperbound]
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set();
    for (auto &e: hnumbers)
        if (bs[e]) {
        // cross out multiples of i starting from i * i!
        for (ll j = e * e; j <= sieve_size; j += e) bs[j] = 0;
        hprimes.push_back(e);
    }
}


int main() {
    ios::sync_with_stdio(0);
    int i = 1;
    while(i <= 250 * 1000 + 10) {
        i += 4;
        hnumbers.push_back(i);
    }
    sieve(250 * 1000);
    int nn = hprimes.size(), n;
    int ii = 0;
    //cout << hprimes.size() << endl;
    //while(hprimes[ii] <= 500) cout << ii << " " << hprimes[ii++] << " " << *upper_bound(hprimes.begin(), hprimes.end(), n / hprimes[ii]) << endl;
    while(cin >> n && n) {
        int sum = 0;
        for(int i = 0; i < nn; i++) {
            if(hprimes[i] > n) break;
            for(int j = i; j < nn && hprimes[j] * hprimes[i] <= n; j++) {
                ll mul = hprimes[j] * hprimes[i];
                if(!bs[mul]) sum++, bs[mul] = 1;
            }
            // int tmp = n / hprimes[i];
            // auto it = upper_bound(hprimes.begin(), hprimes.end(), tmp);
            // sum += it - hprimes.begin() - i < 0 ? 0 : it - hprimes.begin() - i;

        }
        bs.reset();
        cout << n << ' ' << sum << endl;
    }

    return 0;
}
