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

#define inf 100000000
#define eps 1e-9
#define pi acos(-1)

ll sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vll primes;

// create list of primes in [0..upperbound]
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            string s = to_string(i);
            bool b = true;
            for(auto c: s){

                if(c == '1' || c == '3' || c == '7' || c == '9')
                    continue;
                else {
                    b = false;
                    break;
                }
            }
            if(b || s == "5" || s == "2");
                primes.push_back(i);
        }
}

bool isPrime(ll n) {
    if (n <= sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); i++)
        if (n % primes[i] == 0) return false;
    return true;
} // note: only work for n <= (last prime in vi "primes")^2

bool check(ll n){
    string s = to_string(n);
    sort(s.begin(), s.end());
    do{
        if(!bs[stoll(s)])
            return false;
    }
    while(next_permutation(s.begin(), s.end()));

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    sieve(1e7);
    ll n;
    vll pp;

    for(auto n: primes){
        if(check(n))
            pp.push_back(n);
    }

    while(cin >> n && n != 0){
        ll ans = *lower_bound(pp.begin(), pp.end(), n + 1);
        int size = to_string(n).size();

        bool b = to_string(ans).size() == size;

        cout << (b ? ans : 0) << endl;
    }

    return 0;
}
