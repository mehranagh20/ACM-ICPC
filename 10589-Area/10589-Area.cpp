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

int inCir(dd p, dd c, double r) {
    double dx = p.first - c.first, dy = p.second - c.second;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    return rSq >= Euc ? 1 : 2;
}

int main() {
    ios::sync_with_stdio(0);
    int n, a;
    while(cin >> n >> a && n) {
        int m = 0;
        for(int i = 0; i < n; i++) {
            dd p; cin >> p.first >> p.second;
            if(inCir(p, dd(0, 0), a) != 2 && inCir(p, dd(0, a), a) != 2 && inCir(p, dd(a, 0), a) != 2 && inCir(p, dd(a, a), a) != 2)
                m++;
        }
        cout << fixed << setprecision(5) << ((double)m * (double)a * (double)a) / (double)n << endl;
    }


    return 0;
}
