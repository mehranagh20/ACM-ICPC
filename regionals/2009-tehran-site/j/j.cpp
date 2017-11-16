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
        vi leaf(n + 1, 1), par(n + 1, 0), free(n + 1, 1), trap(n + 1, 0);
        leaf[0] = 0;
        int enter;
        for(int i = 0; i < n; i++) {
            int a, b, c; cin >> a >> b >> c;
            if(!a) enter = i + 1;
            leaf[a] = 0, par[i + 1] = a, free[i + 1] = b, trap[i + 1] = c;
        }
        ll ans = inf;
        for(int i = 1; i <= n; i++) if(leaf[i]) {
                ll cur = i, cur_ans = 0;
                while(cur != enter) {
                    cur_ans = (cur_ans + trap[cur]) * 2 + 1;
                    if(free[cur]) cur_ans--;
                    cur = par[cur];
                }
                ans = min(ans, cur_ans);
            }
        cout << ans + trap[enter] << endl;
    }
    return 0;
}
