//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
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
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

const ll MX = 1e5 + 1000;

vi f, x(MX), v(MX);
viii sp, fp;
ll n, w;

void upd(ll pos, ll d){ // add 'd' to pos'th index
	for(; pos < MX; pos |= pos + 1)
		f[pos] += d;
}

ll get(ll pos){ // sum from 0 to pos
	ll res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

bool oper1 (const iii f, const iii s) {
    if(f.F * s.S.F != f.S.F * s.F)
        return f.F * s.S.F > f.S.F * s.F;
    // return abs(v[sp[f.S.S].S.S]) < abs(v[sp[s.S.S].S.S]);
		return f.S.S 	< s.S.S;
}

bool oper2 (const iii f, const iii s) {
    if(f.F * s.S.F != f.S.F * s.F)
        return f.F * s.S.F < f.S.F * s.F;

    return fp[f.S.S].F * fp[s.S.S].S.F > fp[f.S.S].S.F * fp[s.S.S].F;
}

int main() {
	ios::sync_with_stdio(0);

	f.assign(MX, 0);
	cin >> n >> w;
	fp.assign(n, iii()), sp.assign(n, iii	());
    ll ans = 0;
    forn(i, n) {
        cin >> x[i] >> v[i];
        if(x[i] < 0) x[i] = -x[i];
        fp[i] = {x[i], {abs(v[i] - w), i}};
        sp[i] = {x[i], {abs(v[i] + w), i}};
    }

    sort(sp.begin(), sp.end(), oper2);
    forn(i, n)
        fp[sp[i].S.S].S.S = i;

    sort(fp.begin(), fp.end(), oper1);

    forn(i, n) {
        ans += get(fp[i].S.S);
        upd(fp[i].S.S, 1);
    }

    cout << ans << endl;

    return 0;
}
