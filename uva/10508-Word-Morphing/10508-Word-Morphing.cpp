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
    int n, m;
    while(cin >> n >> m) {
        string f, s; cin >> f >> s;
        cout << f << endl;
        vs all(n - 2);
        for(auto &e: all) cin >> e;
        for(int i = 0; i < m; i++) {
            if(f[i] == s[i]) continue;
            for(int j = 0; j < n - 2; j++) if(all[j][i] == s[i]) {
                int num = 0;
                for(int i = 0; i < m; i++) num += (all[j][i] != f[i]);
                if(num == 1) {
                    cout << all[j] << endl;
                    f = all[j];
                }
            }
        }
        cout << s << endl;
    }


    return 0;
}
