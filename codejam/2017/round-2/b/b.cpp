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

vi c1, c2;

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        int n, c, m, ans = 0, pro = 0; cin >> n >> c >> m;
        c1.assign(n, 0), c2.assign(n, 0);
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            if(b == 1) c1[a - 1]++;
            else c2[a - 1]++;
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            if(i != j) {
                int m = min(c1[i], c2[j]);
                c1[i] -= m, c2[j] -= m;
                ans += m;
            }
        }
        for(int i = 1; i < n; i++) if(c1[i] && c2[i]) {
            int m = min(c1[i], c2[i]);
            c1[i] -= m, c2[i] -= m;
            ans += m, pro += m;
        }
        ans += c1[0];
        ans += c2[0];
        for(int i = 1; i < n; i++)
            ans += c1[i], ans += c2[i];
        cout << ans << " " << pro << endl;
    }


    return 0;
}
