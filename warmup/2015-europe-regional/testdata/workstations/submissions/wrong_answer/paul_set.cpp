/*
Use set as priority queue, this is incorrect if the same value gets pushed twice.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define xx first
#define yy second
#define all(c) begin(c), end(c)
#define sz(c) ll((c).size())

int main() {
	ll n, m; cin >> n >> m;
	
	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	sort(all(a));
	
	set<ll> frees, logouts;

	ll res = 0;
	FOR(i,0,n) {
		while (sz(frees) && *begin(frees) <= a[i].xx)
			logouts.insert(*begin(frees) + m), frees.erase(begin(frees));
		while (sz(logouts) && *begin(logouts) < a[i].xx)
			logouts.erase(begin(logouts));
		if (sz(logouts)) {
			res++;
			logouts.erase(begin(logouts));
		}
		frees.insert(a[i].xx + a[i].yy);
	}
	cout << res << endl;
}
