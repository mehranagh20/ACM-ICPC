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

#define inf 1000000000
#define eps 1e-9

#define mx 2001000



ll sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes;

// create list of primes in [0..upperbound]
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    int num = 0;
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
            num++;
            if(num > 10000) break;
        }
}

bool isPrime(ll n) {
    if (n <= sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); i++)
        if (n % primes[i] == 0) return false;
    return true;
} // note: only work for n <= (last prime in vi "primes")^2

// inside main()

int main() {
    ios::sync_with_stdio(0);
    sieve(1000000);
    cout << primes.back() << endl;
    ull tc; cin >> tc;
    while(tc--) {
        ull num; cin >> num;
        num++;
        while(true) {
            while (isPrime(num)) num++;
            string str = to_string(num);
            int s = 0, ss = 0;
            for(auto &e : str) s += e - '0';
            ull tmp = num;
            for(int i = 0; i < primes.size(); i++) if(tmp % primes[i] == 0 || isPrime(tmp)) {
                    int toD = primes[i];
                    if(isPrime(tmp)) toD = tmp;
                    str = to_string(toD);
                    while(tmp % toD == 0) {
                        tmp /= toD;
                        for (auto &e : str) ss += e - '0';
                    }
                }
            if(ss == s) break;
            num++;
        }
        cout << num << endl;

    }

    return 0;
}