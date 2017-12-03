#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)

struct BIT {
	ll n;
	vl bit;
	
	BIT(ll n): n(n) { bit.resize(n+2); }

	void add(ll i, ll v) {
		for (++i; i <= n+1; i += i & -i) bit[i] += v;
	}

	ll getSum(ll i) {
		ll res = 0;
		for (; i; i -= i & -i) res += bit[i];
		return res;
	}
};

ll same(vl a, vl b) {
	ll n = a.size();
	vl ai(n);
	FOR(i,0,n) ai[a[i]] = i;
	FOR(i,0,n) b[i] = ai[b[i]];

	ll res = 0;
	BIT bit(n);
	FOR(i,0,n) res += bit.getSum(b[i]), bit.add(b[i],1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;
	vl a(n), b(n), c(n);
	FOR(i,0,n) cin >> a[i], a[i]--;
	FOR(i,0,n) cin >> b[i], b[i]--;
	FOR(i,0,n) cin >> c[i], c[i]--;
	
	cout << (same(a,b)+same(a,c)+same(b,c)-n*(n-1)/2)/2 << endl;
}

