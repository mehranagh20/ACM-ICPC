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
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    int n, rr, t; cin >> n >> rr >> t;
    vector<pair<int, double>> c = {{t, rr}};
    cout << rr;
    for(int tm = 0; tm < n - 1; tm++) {
        int k; cin >> k;
        int l = k - rr, r = k + rr;
        double y = rr;
        for(auto &e: c) {
            int l2 = e.first - rr, r2 = e.first + rr;
            if(l >= l2 && l <= r2 || r >= l2 && r <= r2) {
                double f = 2 * rr * 2 * rr, s = (k - e.first) * (k - e.first);
                y = max(y, sqrt(f - s) + e.second);
            }
        }
        c.push_back(make_pair(k, y));
        cout << ' ' << fixed << setprecision(10) <<  y;
    }
    cout << endl;


    return 0;
}
