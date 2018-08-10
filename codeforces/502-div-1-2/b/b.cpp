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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    ll z = 0, o = 0, ans = 0;
    forn(i, n) if(a[i] == '0' && b[i] == '1') z++;
    forn(i, n) if(a[i] == '1') o++;
    forn(i, n) if(a[i] == '0' && b[i] == '0') ans += o;
    forn(i, n) if(a[i] == '1' && b[i] == '0') ans += z;
    cout << ans << endl;


    return 0;
}