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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    map<string, set<string>> mp;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string str; int nn;
        cin >> str >> nn;
        for (int j = 0; j < nn; ++j) {
            string p; cin >> p;
            mp[str].insert(p);
        }
    }
    cout << mp.size() << endl;
    for(auto &e: mp) {
        vs all;
        for(auto ee: e.second) {
            bool ok = true;
            for(auto eee: e.second) {
                    if(eee.size() > ee.size()) {
                        bool now = true;
                        string a = ee, b = eee;
                        reverse(a.begin(), a.end());
                        reverse(b.begin(), b.end());
                        for(int i = 0; i < a.size(); i++) if(a[i] != b[i]) now = false;
                        if(now) ok = false;
                    }
                }
            if(ok) all.push_back(ee);
        }
        cout << e.first << " " << all.size();
        for(auto &ee: all) cout << " " << ee;
        cout << endl;
    }


    return 0;
}
