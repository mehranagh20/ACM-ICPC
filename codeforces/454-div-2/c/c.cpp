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
#define F(i, n) for(int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    set<char> f;
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) f.insert(c);
    F(i, n) {
        char ac; string str; cin >> ac >> str;
        if(ac == '!') {
            if(f.size() == 1) ans++;
            set<char> a, b;
            for(auto &e: str) a.insert(e);
            set_intersection(f.begin(), f.end(),a.begin(), a.end(),
                             inserter(b, b.begin()));
            f = b;
        }
        else if(ac == '.') {
            for(auto &e: str)
                f.erase(e);
        }
        else {
            if(f.size() == 1) if(i != n - 1) ans++;
            f.erase(str[0]);
        }
    }
    cout << ans << endl;


    return 0;
}
