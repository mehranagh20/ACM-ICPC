#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

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

ll EulerPhi(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = n;
    while (PF * PF <= n) {
        if (n % PF == 0) ans -= ans / PF;
        while (n % PF == 0) n /= PF;
        PF = primes[++PF_idx];
    }
    if (n != 1) ans -= ans / n;
    return ans;
}

int main() {
	ios::sync_with_stdio(false);

	sieve(10000000); // can go up to 10^7 (need few seconds)

	vi dp(200005, 0);
	for (int i = 1; i < 200001; i++) {
		for (int j = 2 * i; j <= 200001; j += i) {
			dp[j] += i * EulerPhi(j / i);
		}
	}

	for (int i = 1; i < 200001; i++)
		dp[i] += dp[i - 1];

	int n;
	while (cin >> n && n) {
		cout << dp[n] << endl;
	}

	return 0;
}
