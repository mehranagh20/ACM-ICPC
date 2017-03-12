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
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    vector<ull> fac = {1};
    for(int i = 1; i <= 20; i++) fac.push_back(fac.back() * i);
    int tc; cin >> tc;
    while(tc--) {
        string str; cin >> str;
        ull per; cin >> per;
        for(int i = 0; i < str.size(); i++) {
            sort(str.begin() + i, str.end());
            swap(str[i], str[i + per / fac[str.size() - (i + 1)]]);
            per %= fac[str.size() - (i + 1)];
        }
        cout << str << endl;
    }


    return 0;
}
