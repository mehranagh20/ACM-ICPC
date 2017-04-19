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
    sieve(1e2 + 10);
    while(cin >> n >> b && n && b){
        vii PF = primeFactors(b);
        vll counts(PF.size(), 0);
        for(int j = PF.size() - 1; j >= 0; j--){
            auto pf = PF[j].first;
            bool check = true;
            double tm = PF[j].first;
            for(int i = j + 1; i < PF.size(); i++) {
                int tmpp = ceil(PF[i].first / tm) + eps;
                if(PF[j].second < tmpp * PF[i].second) {
                    check = false;
                    break;
                }
            }
            if(!check) {
                counts[j] = -1;
                continue;
            }
            //cout << "pf is " << pf << endl;
            for (ll i = pf; i <= n; i += pf) {
                ll base = 0, tmp = i;
                while(tmp % pf == 0) tmp /= pf, base++;
                ll c = n - i + 1;
                ll power = (c * (c+1)) / 2;
                counts[j] += base * power;
                //cout << "i is " << i << " count is " << counts[j] << endl;
            }
        }
        ll ans = counts[PF.size() - 1];
        //cout << PF[0].first << " " << counts[0] << endl << PF[1].first << " " << counts[1] << endl;
        //cout << (double) counts[0] / counts[1] << endl;
        for (int i = 0; i < PF.size(); ++i)
            if(counts[i] != -1)
                ans = min(ans, counts[i] / PF[i].second);
        cout << ans << endl;
    }

    return 0;
}
