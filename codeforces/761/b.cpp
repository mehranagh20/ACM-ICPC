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
    int tc; cin >> tc;
    while(tc--) {
        int n, l, all = 0, pre;cin >> n >> l;
        vi a, b;
        cin >> pre;
        for(int i = 0; i < n - 1; i++) {
            int tmp; cin >> tmp;
            a.push_back(tmp - pre), all += tmp - pre;
            pre = tmp;
        }
        a.push_back(l - all), all = 0;
        cin >> pre;
        for(int i = 0; i < n - 1; i++) {
            int tmp; cin >> tmp;
            b.push_back(tmp - pre), all += tmp - pre;
            pre = tmp;
        }
        b.push_back(l - all);
        bool pos = false;
        for(int i = 0; i < n && !pos; i++) if(a[i] == b[0]) {
            int cur = 1, ii = i, j = 0;
            for(; j < n; j++) {
                if(ii >= n) break;
                if(b[j] != a[ii]) cur = 0;
                ii++;
            }
            ii = 0;
            for(; j < n; j++) {
                if(b[j] != a[ii]) cur = 0;
                ii++;
            }
            if(cur) pos = true;
        }
        if(pos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
