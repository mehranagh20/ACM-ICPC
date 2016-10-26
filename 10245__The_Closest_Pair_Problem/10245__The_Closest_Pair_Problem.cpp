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
#define eps 1e-7

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        vdd coors;
        double ans = 1e8;
        for(int i = 0; i < n; i++) {
            double a, b; cin >> a >> b;
            for(auto &e : coors) if(ans - (pow(e.first - a, 2) + pow(e.second - b, 2)) > eps)
                    ans = pow(e.first - a, 2) + pow(e.second - b, 2);
            coors.push_back(dd(a, b));
        }
        if(ans == 1e8) cout << "INFINITY\n";
        else cout << setprecision(4) << fixed << sqrt(ans) << endl;
    }

    return 0;
}