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
    int a, b, c, d; cin >> a >> b >> c >> d;
    for(int i = 2; i <= 300; i++) {
        for (int j = 2; j <= 300; ++j) {
            for (int k = 2; k <= 300; ++k) {
                if(i >= a && j >= b && k >= c && i >= d && j >= d && k >= d) {
                    if(i <= 2 * a && j <= 2 * b && k <= 2 * c && k <= 2 * d) {
                        if(i > j && j > k) {
                            cout << i << endl << j << endl << k << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;


    return 0;
}
