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
typedef vector<int> vi;
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

ll gcd(ll a, ll b) {
  return (b == 0? a : gcd(b, a % b));
}

int main() {
    ios::sync_with_stdio(0);
    ll n, k, g, t, c; cin >> n >> k;
    cin >> g;
    forn(i, n - 1)
      cin >> t, g = gcd(g, t);

    set<ll> ans;
    c = g;
    while(1) {
      int cur = c % k;
      if(ans.find(cur) != ans.end())
        break;
      ans.insert(cur), c += g;
    }

    cout << ans.size() << endl;
    for(auto &e: ans) cout << e << " ";

    return 0;
}
