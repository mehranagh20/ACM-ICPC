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
#define eps 1e-7

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && (n >= 0)) {
        int ans = -1, tmp = sqrt(n);
        for (int i = tmp; i >= 2; i--)
            if (n % i == 1) {
                int nn = n;
                bool pos = true;
                for (int j = 0; j < i; j++) {
                    if (nn % i == 1) nn -= (nn / i) + 1;
                    else {
                        pos = false;
                        break;
                    }
                }
                if (pos && (nn % i == 0)) {
                    ans = i;
                    break;
                }
            }
        if(n == 3) ans = 2;
        if(ans == -1) cout << n << " coconuts, no solution" << endl;
        else cout << n << " coconuts, " << ans << " people and 1 monkey" << endl;
    }

    return 0;
}