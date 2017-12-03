#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
const ll oo = 0x3f3f3f3f3f3f3f3f;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define pb push_back
#define xx first
#define yy second

int main() {
	ll n, k; cin >> n >> k;
	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	
	vector<pll> b;
	vl extra;
	FOR(i,0,n) {
		bool isextra = false;
		FOR(j,0,n) {
			if (a[i].xx <= a[j].xx && a[j].yy <= a[i].yy
				&& (a[i].xx != a[j].xx || a[i].yy != a[j].yy || i < j)) isextra = true;
		}
		if (isextra) extra.pb(a[i].yy-a[i].xx);
		else b.pb(a[i]);
	}
	sort(all(b));
	sort(all(extra),greater<ll>());

	n = sz(b);

	vvl dp(n+1,vl(k+1,-oo));
	dp[0][0] = 0;
	FOR(i,0,n) FOR(j,0,k) {
		FORD(ii,0,i+1) {
			ll w = b[ii].yy - b[i].xx;
			if (w <= 0) break;
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[ii][j] + w);
		}
	}
	
	ll res = dp[n][k];
	ll extrasum = 0;
	FOR(i,0,min(sz(extra),k)) {
		extrasum += extra[i];
		res = max(res, dp[n][k-i-1] + extrasum);
	}
	cout << res << endl;

}

