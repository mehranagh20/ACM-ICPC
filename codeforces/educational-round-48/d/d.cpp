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
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    int n, m, rx = 0, cx = 0; cin >> n >> m;
    vi r(n), c(m);
    forn(i, n) cin >> r[i], rx ^= r[i];
    forn(i, m) cin >> c[i], cx ^= c[i];
    if(rx != cx) {
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES\n";
    forn(i, n) {
      forn(j, m) {
        if(i == n - 1 && j < m - 1) cout << c[j] << ' ';
        else if(i < n - 1 && j == m - 1) cout << r[i] << ' ';
        else if(i < n - 1 && j < m - 1) cout << "0 ";
        else {
          rx = 0;
          for(int i = 0; i < m - 1; i++) rx ^= c[i];
          cout << (r[n - 1] ^ rx) << ' ';
        }
      }
      cout << endl;
    }

    return 0;
}