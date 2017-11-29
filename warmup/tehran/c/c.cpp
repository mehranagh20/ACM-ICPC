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
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vii tmp(n);
        int ans = -1;
        for(int i = 0; i < n; i++) cin >> tmp[i].first >> tmp[i].second;
        for(int j = 0; j < n; j++) {
            int s = 0;
            bool ok = true;
            for (int i = j; i < n; i++) {
                int a = tmp[i].first, b = tmp[i].second;
                s += tmp[i].first;
                if (s < b) {
                    ok = false;
                    break;
                }
                s -= b;

            }
            for(int i = 0; i < j; i++) {
                int a = tmp[i].first, b = tmp[i].second;
                s += a;
                if (s < b) {
                    ok = false;
                    break;
                }
                s -= b;
            }
            if(ok) {
                ans = j;
                break;
            }
        }
        if(ans != -1) cout << ans << endl;
        else cout << "it's a trap" << endl;
    }


    return 0;
}
