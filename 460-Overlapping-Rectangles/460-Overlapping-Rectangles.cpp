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
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        ii a, b, c, d;
        cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
        int ii = max(a.first, c.first), jj = max(c.second, a.second), kk = min(b.first, d.first), dd = min(b.second, d.second);
        if(ii >= kk || jj >= dd) cout << "No Overlap\n"; // if lower left point is above or to the left of upper right point
        else
            cout << ii << ' ' << jj << ' ' << kk << ' ' << dd << endl;
    }


    return 0;
}
