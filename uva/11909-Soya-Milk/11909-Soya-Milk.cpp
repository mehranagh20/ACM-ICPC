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

double degToRad(double theta){ return theta * pi / 180.0; }

int main() {
    ios::sync_with_stdio(0);
    int l, w, h;
    double theta;
    while(cin >> l >> w >> h >> theta){
        double m = l * tan(degToRad(theta));

        if(m - h > eps) {
            m = h * tan(degToRad(90 - theta));
            cout << fixed << setprecision(3) << (w * h * m) / 2;
        } else
            cout << fixed << setprecision(3) <<  w * h * l - ((w * m * l) / 2);

        cout << " mL\n";
    }

    return 0;
}
