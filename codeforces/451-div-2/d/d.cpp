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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    ll n, k, m; cin >> n >> m >> k;
    vi cl(1e6 + 10, 0);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        cl[a]++;
    }
    ll sum = 0;
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        sum += cl[i];
        if(sum >= k) {
            sum--;
            cl[i] = 0;
            ans++;
        }
    }
    for(int i = m + 1; i <= 1e6 + 10; i++) {
        sum += cl[i] - cl[i - m];
        if(sum >= k) {
            sum--;
            cl[i] = 0;
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
