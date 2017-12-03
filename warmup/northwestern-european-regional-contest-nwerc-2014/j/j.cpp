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
        map<string, int> mp1, mp2;
        for (int i = 0; i < n; ++i) {
            string tmp; cin >> tmp;
            mp1[tmp]++;
        }
        for (int i = 0; i < n; ++i) {
            string tmp; cin >> tmp;
            mp2[tmp]++;
        }
        int ans = 0;
        for(auto &e: mp1) ans += min(e.second, mp2[e.first]);
        cout << ans << endl;

    }


    return 0;
}
