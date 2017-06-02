//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))

int main() {
    ios::sync_with_stdio(0);
    double d, v;
    while (cin >> d >> v && (d != 0 && v != 0)){

        double high = d, low = 0;
        while(high - low > eps){
            double mid = (high + low) / 2.0;
            double right = pi * pow(d, 3) / 4 -
                    (pi * (d - mid) * (d * d + pow(mid, 2) + mid * d) / 12 + pi * pow(mid, 3) / 4);

            if(v - right > eps)
                high = mid;
            else
                low = mid;
        }
        cout << fixed << setprecision(3) << high << endl;

    }

    return 0;
}
