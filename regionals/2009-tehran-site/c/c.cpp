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
    int n;
    while(cin >> n && n) {
        int ans = 0;
        vii bef;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            ans += 4;
            vi used(4, 0);
            for(auto &e: bef) {
                if(e.first == a) {
                    if(e.second + 1 == b) used[3] = 1;
                    if(e.second - 1 == b) used[2] = 1;
                }

                if(e.second == b) {
                    if(e.first + 1 == a) used[1] = 1;
                    if(e.first - 1 == a) used[0] = 1;
                }
            }
            for(auto &e: used) ans -= 2 * e;
            bef.push_back(ii(a, b));
        }
        cout << ans << endl;
    }


    return 0;
}
