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
typedef vector<ll> vi;
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

bool is(string a, string b) {
    if(a.size() > b.size()) return false;
    for (int i = 0; i < min(a.size(), b.size()); ++i)
        if(a[i] != b[i]) return false;
    return true;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = s.size();
    for(int i = 1; i < s.size(); i++) {
        string m;
        for(int j = 0; j < i; j++) m += s[j];
        string x = m + m;
        if(is(x, s))
            ans = min(ans, i + 1 + (int)(s.size() - x.size()));
    }

    cout << ans << endl;


    return 0;
}

