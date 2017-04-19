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

double dis(dd a, dd b) {
    double aa = pow(a.first - b.first, 2), bb = pow(a.second - b.second, 2);
    return sqrt(aa + bb);
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    pair<double, double> a, b;
    while(cin >> n >> a.first >> a.second >> b.first >> b.second) {
        vdd coors(n);
        for(int i = 0; i < n; i++) cin >> coors[i].first >> coors[i].second;
        dd pos = dd(-inf, -inf);
        for(auto &e : coors) {
            ll gof = (dis(e, a) + eps) * 1000, dog = (dis(e, b) + eps) * 1000;
            if(gof * 2 <= dog) {
                pos = e;
                break;
            }
        }
        if(pos == dd(-inf, -inf)) cout << "The gopher cannot escape.\n";
        else cout << "The gopher can escape through the hole at (" << fixed << setprecision(3) << pos.first << "," << fixed << setprecision(3) << pos.second << ")." << endl;
    }

    return 0;
}
