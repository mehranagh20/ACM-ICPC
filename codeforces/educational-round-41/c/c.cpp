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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

vs solve(vs s, char c, int n) {
   s[0][0] = c;
        for(int i = 0; i < 2 * n; i++)
            for(int j = 0; j < 2 * n; j++) {
                if(i && s[i - 1][j] == s[i][j]) {
                    if(s[i][j] == '1')
                    s[i][j] = '0';
                    else s[i][j] = '1';
                }
                if(j && s[i][j - 1] == s[i][j]) {
                    if(s[i][j] == '1')
                        s[i][j] = '0';
                    else s[i][j] = '1';
                }
            }
    return s;
}


int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<vs> grids(4, vs(n));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) cin >> grids[i][j];
    }
    sort(grids.begin(), grids.end());

    int ans = inf;

    do {
        vs s(2 * n);
        for(int i = 0; i < n; i++) {
            string str = grids[0][i] + grids[1][i];
            s[i] = str;
        }
        for(int i = 0; i < n; i++) {
            string str = grids[2][i] + grids[3][i];
            s[i + n] = str;
        }

        vs cur = solve(s, '0', n);
        int ci = 0, ci2 = 0;
        for(int i = 0; i < 2 * n; i++) for(int j = 0; j < 2 * n; j++)
                if(cur[i][j] != s[i][j]) ci++;
        cur = solve(s, '1', n);
        for(int i = 0; i < 2 * n; i++) for(int j = 0; j < 2 * n; j++)
                if(cur[i][j] != s[i][j]) ci2++;
        ci = min(ci, ci2);
        ans = min(ans, ci);


    } while(next_permutation(grids.begin(), grids.end()));
    cout << ans << endl;

    return 0;
}