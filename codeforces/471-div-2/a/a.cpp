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
typedef vector<ll> vi;
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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back


int main() {
    ios::sync_with_stdio(0);
    int h, m; cin >> h >> m;
    int hh, d, c, nn; cin >> hh >> d >> c >> nn;
    if(h >= 20) {
        double s = (ceil((double)hh / nn)) * c * .8;
        cout << fixed << setprecision(8) << s << endl;
        exit(0);
    }
    int n = ((19 - h + 24) % 24) * 60 + (60 - m);
    double f = (ceil(((double)(n * d + hh) / nn))) * c * .8;
    double s = (ceil((double)hh / nn)) * c;
    cout << fixed << setprecision(8) << min(f, s);



    return 0;
}

