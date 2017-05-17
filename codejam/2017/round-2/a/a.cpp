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
    for(int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        int n, p, ans = 0; cin >> n >> p;
        vi rem(4, 0);
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            rem[tmp % p]++;
        }
        if(p == 2)
            ans = rem[0] + (rem[1] & 1 ? rem[1] / 2 + 1 : rem[1] / 2);
        if(p == 3) {
            ans = rem[0];
            int m = min(rem[1], rem[2]);
            rem[1] -= m, rem[2] -= m;
            ans += m;
            if(rem[1] % 3 == 0) ans += rem[1] / 3;
            else ans += rem[1] / 3 + 1;
            if(rem[2] % 3 == 0) ans += rem[2] / 3;
            else ans += rem[2] / 3 + 1;
        }
        if(p == 4) {
            ans = rem[0];
            if(rem[2] % 2 == 0) ans += rem[2] / 2;
            else ans += rem[2] / 2, rem[2] = 1;
            int m = min(rem[1], rem[3]);
            ans += m;
            rem[1] -= m, rem[3] -= m;
            if(rem[2]) {
                if(rem[3] >= 2) ans += 1, rem[2] = 0, rem[3] -= 2;
                else if(rem[1] >= 2) ans += 1, rem[2] = 0, rem[1] -= 2;
            }
            if(rem[3] % 4 == 0) ans += rem[3] / 4;
            else ans += rem[3] / 4 + 1;
            if(rem[1] % 4 == 0) ans += rem[1] / 4;
            else ans += rem[1] / 4 + 1;
        }
        cout << ans << endl;
    }


    return 0;
}
