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

int n, m;
vvi rows, cols;

int main() {
    ios::sync_with_stdio(0);
    int k = 0;
    while(cin >> n >> m){
        rows.assign(n+1, vi(n+1, 0));
        cols.assign(n+1, vi(n+1, 0));
        for (int i = 0; i < m; ++i) {
            char c; int a, b; cin >> c >> a >> b;
            if(c == 'H')
                for (int j = b+1; j < n+1; ++j)
                    rows[a][j]++;
            else
                for (int j = b+1; j < n+1; ++j)
                    cols[a][j]++;
        }


        vi ans(n+1, 0); bool found = false;
        for (int l = 1; l < n; ++l) {
            for (int i = 1; i <= n; ++i) {
                if(i + l > n) continue;
                for (int j = 1; j <= n; ++j) {
                    if(j + l > n) continue;
                    if((rows[i][j+l] - rows[i][j] == l) && (cols[j][i+l] - cols[j][i] == l) &&
                        (rows[i+l][j+l] - rows[i+l][j] == l) && (cols[j+l][i+l] - cols[j+l][i] == l))
                        ans[l]++, found = true;
                }
            }
        }

        if(k)
            cout << "\n**********************************\n\n";
        cout << "Problem #" << ++k << endl << endl;

        if(!found)
            cout << "No completed squares can be found.\n";
        else
            for (int i = 0; i < n + 1; ++i) if(ans[i])
                cout << ans[i] << " square (s) of size " << i << endl;
    }

    return 0;
}
