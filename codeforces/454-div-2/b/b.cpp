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
typedef vector<int> vi;
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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back
#define F(i, n) for(int i = 0; i < n; i++)

bool fill(vs &grid) {
    bool found = false;
    F(i, 3) F(j, 3) if(grid[i][j] == '.') {
                grid[i][j] = '!';
                found = true;
            }
    return found;
}

int main() {
    ios::sync_with_stdio(0);
    vector<vector<vs>> grid(3, vector<vs>(3, vs(3, "   ")));
    F(i, 3) F(j, 3) F(k, 3) F(d, 3) {
                cin >> grid[i][k][j][d];
            }
    int i, j; cin >> i >> j;
    i--, j--;
    if(!fill(grid[i % 3][j % 3])) F(k, 3) F(d, 3) fill(grid[k][d]);

    F(i, 3) {
        if(i) cout << endl;
        F(j, 3) {
            F(k, 3) {
                if (k) cout << ' ';
                F(d, 3) {
                    cout << grid[i][k][j][d];
                }

            }
            cout << endl;
        }
    }


    return 0;
}
