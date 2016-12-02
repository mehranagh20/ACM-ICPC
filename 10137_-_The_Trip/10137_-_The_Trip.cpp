//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        vd mon(n);
        double tot = 0, f = 0, s = 0, tmp;
        for(int i = 0; i < n; i++) {
            cin >> mon[i];
            tot += mon[i];
        }
        tot /= n;
        for(auto &e : mon) {
            int dif = ((e - tot) * 100.0); // for within one cent
            if(dif < 0) s += dif;
            else f += dif;
        }
        cout << setprecision(2) << fixed << "$" << (fabs(s) > f ? fabs(s) : f) / 100 << endl;
    }

    return 0;
}