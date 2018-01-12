//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
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

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    set<ii> s;
    for(int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; ++j) {
            s.insert(ii(i, j));
        }
    int ans = 0;
    while(s.size()) {
        ans++;
        int l = s.begin()->second;
        s.erase(s.begin());
        set<ii> ss = s;
        while(1) {
            ii f = {l, inf};
            for(auto &e: ss) if(e.first >= l)
                    if(e.second < f.second) f = e;
            if(f == ii(l, inf)) break;
            l = f.second;
            s.erase(f);
        }
    }
    cout << ans << endl;


    return 0;
}
