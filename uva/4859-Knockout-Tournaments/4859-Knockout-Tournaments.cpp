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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    ll w, l, tc = 0;
    while(cin >> w >> l && (w || l)) {
        ll num = 0;
        double all = 0;
        for(ll x = l; x <= w / 8 + l; x++) {
            if((x - l) * 8 <= w && w <= (x - l) * 8 + 7 * l) {
                all += ((x - l) * 8. + (w - (x - l) * 8 + l)) / x;
                num++;
            }
        }

        cout << "Case " << ++tc << ":\n";
        if(num) {
            cout << "On Average Bob Reaches Round ";
            cout << fixed << setprecision(2) << all / num << endl;
        }
        else cout << "Situation Impossible." << endl;
    }


    return 0;
}
