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
#define pi 3.14159

int main() {
    ios::sync_with_stdio(0);
    double a, b, v, d, s;
    while(cin >> a >> b >> v >> d >> s && (a || b || v || d || s)) {
        double dis = v * s / 2; // x = ((v1 + v2) / 2) * t <--- remember the formula ??
        cout << round(cos(d / 180 * pi) * dis / a) << " " << round(sin(d / 180 * pi) * dis / b) << endl;
    }

    return 0;
}