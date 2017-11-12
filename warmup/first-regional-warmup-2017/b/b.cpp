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
    ll m, w;
    while(cin >> m >> w && m && w) {
        ll a, b, c; cin >> a >> b >> c;
        ull ans = 0;
        for(int k = 0; k <= m; k++)
            for (int i = 0; i <= m; ++i) {
                ll cur = k * a + i * b;
                if(w >= cur && (w - cur) % c == 0 && (w - cur) / c <= m)
                    ans++;
                cur = i * a + k * b;
                if(cur > w && abs(w - cur) % c == 0 && abs(w - cur) / c <= m) {
                    ans++;
                }
                cur = i * c + k * b;
                if(cur > w && abs(w - cur) % a == 0 && abs(w - cur) / a <= m) {
                    ans++;
                }
                cur = i * c + k * a;
                if(cur > w && abs(w - cur) % b == 0 && abs(w - cur) / b <= m) {
                    ans++;
                }
            }
        cout << ans << endl;
    }


    return 0;
}
