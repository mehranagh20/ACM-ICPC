// In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
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

#define inf 1000000000
#define eps 1e-9

int modulo(ll a, ll b, ll n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n; // squaring the base
    b /= 2;
  }
  return x % n;
}

int main() {
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    ll n, k, mod;
    cin >> n >> k >> mod;
    ll f = (modulo(n, k - 1, mod) % mod * (k % mod)) % mod;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      res = (res + (tmp * f)) % mod;
    }
    cout << "Case " << t + 1 << ": " << res << endl;
  }

  return 0;
}
