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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vi tmp(n);
    for(auto &e: tmp) cin >> e;
    vi tmp2 = tmp;
    sort(tmp2.begin(), tmp2.end());
    int m = tmp2[0];
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if(tmp[j] == m) {
            i = j;
            break;
        }
    }
    int ans = inf;
    for(int k = i + 1; k < n; k++) {
        if(tmp[k] == m) {
            ans = min(ans, k - i);
            i = k;
        }
    }
    cout << ans << endl;


    return 0;
}
