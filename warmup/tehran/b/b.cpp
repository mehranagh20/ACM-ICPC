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
        int n, m; cin >> n >> m;
        map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            mp1[tmp]++;
        }
        for(int i = 0; i < m; i++) {
            int tmp; cin >> tmp;
            mp2[tmp]++;
        }
        int ans = 0;
        for(map<int, int>::iterator it = mp1.begin(); it != mp1.end(); it++) {
            ans += min(it->second, mp2[it->first]);
        }
        cout << ans << endl;
    }


    return 0;
}
