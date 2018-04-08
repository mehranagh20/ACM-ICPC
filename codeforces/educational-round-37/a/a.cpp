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

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi x(n, 0);
        for (int i = 0; i < k; ++i) {
            int a;
            cin >> a;
            x[a - 1] = 1;
        }
        int ans = 1;
        while (true) {
            bool ok = true;
            for (int i = 0; i < n; i++) if (x[i] == 0) ok = false;
            if (ok) break;
            ans++;
            for(int i = 0; i < n; i++) if(x[i] == 1) {
                    if(i - 1 >= 0 && x[i - 1] == 0) x[i - 1] = 2;
                    if(i + 1 < n && x[i + 1] == 0) x[i + 1] = 2;
                }
            for (int j = 0; j < n; ++j) {
                if(x[j] == 2) x[j] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}