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
    int n, m;
    vi cards = {1, 10, 100, 1000, 10000};
    while(cin >> n >> m) {
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int bd, sum = 0, first; cin >> bd;
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    cin >> first; sum = first;
                    continue;
                }
                int tmp; cin >> tmp;
                sum += tmp;
            }
            int tmp = 0;
            for(auto &e : cards) if(sum - first + e <= bd) tmp = e;
            if(tmp >= first) ans += tmp - first;
            else ans += tmp;
        }
        cout << ans << endl;
    }

    return 0;
}
