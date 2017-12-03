#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
#define sz(c) ll((c).size())
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))

bool find_match(ll i, vvl &adj, vl &pred, vb &mark) {
	if (i == -1) return true;
	for (ll j: adj[i]) if (!mark[j]) {
		mark[j] = true;
		if (find_match(pred[j],adj,pred,mark)) {
			pred[j] = i;
			return true;
		}
	}
	return false;
}

ll max_matching(vvl &adj, vl &pred) {
	ll m = sz(adj), n = sz(pred), res = 0;
	FOR(i,0,m) {
		vb mark(n);
		if (find_match(i,adj,pred,mark)) res++;
	}
	return res;
}

int main() {
	ll n; cin >> n;
	vvl adj(n);
	vl a(n), b(n), c(n);
	map<ll,ll> id; ll m = 0;
	FOR(i,0,n) {
		cin >> a[i] >> b[i];
		for (ll x: {a[i]+b[i],a[i]-b[i],a[i]*b[i]}) {
			if (!has(id,x)) id[x] = m++;
			adj[i].pb(id[x]);
		}
	}

	vl pred(m,-1);
	if (max_matching(adj,pred) < n) {
		cout << "impossible" << endl;
		return 0;
	}
	
	for (auto p: id) if (pred[p.yy] != -1) c[pred[p.yy]] = p.xx;

	FOR(i,0,n) {
		cout << a[i];
		if (a[i]+b[i] == c[i]) cout << "+";
		else if (a[i]-b[i] == c[i]) cout << "-";
		else cout << "*";
		cout << b[i] << "=" << c[i] << endl;
	}
}

