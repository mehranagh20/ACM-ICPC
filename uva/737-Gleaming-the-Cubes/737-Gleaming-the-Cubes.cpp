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
    int n;
    while(cin >> n && n) {
        n--;
        int  lower_x, lower_y , lower_z, l;
        cin >> lower_x >> lower_y >> lower_z >> l;
        int upper_x = lower_x + l, upper_y = lower_y + l , upper_z = lower_z + l;
        while(n--) {
            int x, y, z; cin >> x >> y >> z >> l;
            lower_x = max(lower_x, x); lower_y = max(lower_y, y); lower_z = max(z, lower_z);
            upper_x = min(upper_x, x + l); upper_y = min(upper_y, y + l); upper_z = min(z + l, upper_z);
        }
        int sz = (upper_x - lower_x) * (upper_y - lower_y) * (upper_z - lower_z);
        sz = sz < 0 ? 0 : sz;
        cout << sz << endl;

    }


    return 0;
}
