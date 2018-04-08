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
    while(tc--) {
        int m, n; cin >> m >> n;
        vi tmp(m);
        int ind = 0, dir;
        for(int i = 0; i < m; i++) {
            cin >> tmp[i];
            if(tmp[i] == 2) ind = i, dir = 1;
            if(tmp[i] == 3) ind = i, dir = -1;
        }
        int ans = 0;
        while(n--) {
            if(ind == m - 1) {
                ind = m - 2;
                dir = -1;
            }
            else if(ind == 0) {
                ind = 1;
                dir = 1;
            }
            else ind += dir;
            ans += (tmp[ind] == 0);
        }
        cout << ans << endl;
    }


    return 0;
}
