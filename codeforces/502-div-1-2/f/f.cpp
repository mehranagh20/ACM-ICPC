//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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

#define forn(i, n) for (int i = 0; i < n; i++)
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

unsigned int ans = 0, A, B, C, D;

const int SQRT_MX = 20000; // sqrt of maximum number of n
bool bl[SQRT_MX + 10]; // use as cross-by table
ll primes[SQRT_MX + 10]; // stores primes till SQRT_MX

ll getf(int x) {
    return A * x * x * x + B * x * x + C * x + D;
}

ll getContr(ll n, ll p) {
    ll res = 0, cur = n / p;
    while(cur > 0)
        res += cur , cur /= p;
    return res;
}

void blockSieve(ll n) { // same complexity as original sieve, memory complexity is O(sqrt(n) * 2) instead of O(n)
    ll cnt = 0;
    memset(bl, false, sizeof bl);
    for (int i = 2; i <= SQRT_MX; ++i)
        if (!bl[i]) {
            primes[cnt++] = i;
            if (i * 1ll * i <= SQRT_MX)
                for (int j = i * i; j <= SQRT_MX; j += i)
                    bl[j] = true;
        }

    for (int k = 0, maxk = n / SQRT_MX; k <= maxk; ++k) {
        memset(bl, false, sizeof bl);
        int start = k * SQRT_MX;
        for (int i = 0; i < cnt; ++i) {
            int start_idx = (start + primes[i] - 1) / primes[i];
            int j = max(start_idx, 2) * primes[i] - start;
            for (; j < SQRT_MX; j += primes[i])
                bl[j] = true;
        }
        if (k == 0)
            bl[0] = bl[1] = true;
        for (int i = 0; i < SQRT_MX && start + i <= n; ++i)
            if (!bl[i])
                ans += getContr(n, i + start) * getf(i + start);
    }
}


int main() {
    ios::sync_with_stdio(false);

    ll n; cin >> n >> A >> B >> C >> D;
    blockSieve(n);
    cout << ans << endl;

    return 0;
}