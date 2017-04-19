#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <stack>
#include <list>
#include <iomanip>

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
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define inf 1000000000
#define eps 1e-9

int r, c, m, n;
vi num;

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int t = 1; t <= tc; t++){
        cin >> r >> c >> m >> n;
        num.assign(26, 0);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char tm; cin >> tm;
                num[tm - 65]++;
            }
        }

        int mx = *max_element(num.begin(), num.end()), ans = 0;
        for(auto &e: num) {
            if(e == 0) continue;
            if (e == mx)
                ans += e * m;
            else
                ans += e * n;
        }

        cout << "Case " << t << ": " << ans << endl;

    }
    return 0;
}
