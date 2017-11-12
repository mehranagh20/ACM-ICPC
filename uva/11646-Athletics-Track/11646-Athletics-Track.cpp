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
    double a, b;
    int tc = 1;
    char c;
    while(cin >> a >> c >> b) {
        double low = 0, high = 500, w , l;
        while(abs(high - low) > eps) {
            l = (high + low) / 2;
            w = (double)b / a * l;
            double wanted = (400 - 2 * l) / 2;
            double r = sqrt(.25 * l * l + .25 * w * w);
            double deg = 2 * atan(w / l) * 180 / acos(-1);
            double cur = deg / 360 * acos(-1) * (2 * r);
            if(cur > wanted) high = l;
            else low = l;
        }
        cout << "Case " << tc++ << ": " << fixed << setprecision(8) << l << " " << w << endl;

    }


    return 0;
}
