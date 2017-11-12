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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int s, t;
vvi prim;

int bfs() {
    vi dis(t + 110, inf); dis[s] = 0;
    queue<int> q; q.push(s);
    while(q.size()) {
        int cur = q.front(); q.pop();
        if(cur == t) return dis[cur];
        for(auto &e: prim[cur]) if(e != cur && e + cur <= t && dis[e + cur] == inf) {
            dis[e + cur] = dis[cur] + 1;
            q.push(e + cur);
            if(e + cur == t) return dis[e + cur];
        }
    }
    return -1;
}

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
vi primeFactors(ll n) {
    int tmp = n;
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            n /= PF;
            if(PF != tmp)
                factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(n); // special case if n is a prime
    return factors;
}


int main() {
    ios::sync_with_stdio(0);
    int tc = 1;
    sieve(10010);
    prim.assign(10110, vi());
    for(int s = 1; s < 10100; s++)
        prim[s] = primeFactors(s);

    while(cin >> s >> t && (s || t)) {
        cout << "Case " << tc++ << ": " << bfs() << endl;
    }


    return 0;
}
