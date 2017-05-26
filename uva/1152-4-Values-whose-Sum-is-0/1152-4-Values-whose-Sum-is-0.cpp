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
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        int n, ind = 0, ans = 0; cin >> n;
        vi a(n), b(n), c(n), d(n);
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
        vi sums(n * n);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            sums[ind] = c[i] + d[j], ind++;
        sort(sums.begin(), sums.end());
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            int num = -(a[i] + b[j]);
            auto it = lower_bound(sums.begin(), sums.end(), num);
            auto it2 = upper_bound(sums.begin(), sums.end(), num);
            if(*it == num && *(it2 - 1) == num && it != sums.end()) ans += distance(it, it2);
        }
        cout << ans << endl;
    }


    return 0;
}
