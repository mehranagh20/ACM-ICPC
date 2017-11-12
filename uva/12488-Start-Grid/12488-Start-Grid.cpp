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
    while(cin >> n) {
        vi f(n + 1), s(n + 1);

        for(int i = 1; i <= n; i++)
            cin >> f[i];

        for(int i = 1; i <= n; i++)
            cin >> s[i];

        int ans = 0;
        for(int i = n; i >= 1; i--) if(s[i] != f[i]) {
            for(int j = 1; j <= n; j++) if(f[j] == s[i]) {
                while(s[i] != f[i]) {
                    swap(f[j], f[j + 1]);
                    ans++;
                    j++;
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}
