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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
//typedef set<int> si;
//typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<string, int> si;

#define inf 1000000000
#define eps 1e-9

#define mx 2001000

int main() {
    ios::sync_with_stdio(0);
    ull u;
    while(cin >> u) {
        double f = log2(u), s = log2(u + 1), hlp = log2(10);
        int mi = to_string(u).size() + 1, ma = 1e7, k = -1;
        for(int a = mi; a < ma; a++) {
            if(floor(s + a * hlp) >= ceil((f + a * hlp)))
                k = ceil(f + a * hlp), ma = a - 1;
        }
        if(k == -1) cout << "no power of 2\n";
        else cout << k << endl;
    }

    return 0;
}