#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
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

int main() {
	ios::sync_with_stdio(false);

	// inside main()
	sieve(1000000); // can go up to 10^7 (need few seconds)

	int n;
	while (cin >> n && n){
		vi joseph(n, 0);
		for (int i = 0; i < n; i++)
			joseph[i] = i + 1;
		int p = 0;
		int i = 0;
		// int size = n;
		while (joseph.size() > 1) {
			// cerr << i << endl;
			i--;
			// joseph[i] = 1;
			// size--;
			(i += primes[p]) %= joseph.size();
			// while (joseph[i])
				// (++i) %= joseph.size();
			joseph.erase(joseph.begin() + i);
			p++;
			// for (int j = 0; j < joseph.size(); j++)
			// 	cerr << joseph[j] << ' ';
			// cerr << endl;
		}
		// for (int i = 0; i < n; i++)
		// 	if (!joseph[i])
		// 		cout << i + 1 << endl;
		cout << joseph[0] << endl;
	}

	return 0;
}
