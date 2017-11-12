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
    while(tc--) {
        int n; cin >> n;
        vi l, nl;
        for(int i = 0; i < n; i++) {
            int a, b; char c;
            cin >> a >> b >> c;
            if(b && c == 'c') l.push_back(a);
            if(!b && c == 'i') nl.push_back(a);
        }
        int ans = 0;
        sort(l.begin(), l.end());
        for(int i = 0; i < nl.size(); i++) {
            auto it = lower_bound(l.begin(), l.end(), nl[i]);
            while(it != l.end() && *it == nl[i]) it++;
            if(it != l.end())
                ans += l.size() - distance(l.begin(), it);
        }
        cout << ans << endl;
    }

    return 0;
}
