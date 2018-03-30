//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef pair<ld, ld> dd;
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


int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    string str; cin >> str;
    bool pos = false;
    for(int i = 0; i < n; i++) if(str[i] == '?') {
            if(i == 0 || i == n - 1 || str[i - 1] == '?' || str[i + 1] == '?' || str[i - 1] == str[i + 1])
                pos = true;
        }

    for(int i = 0; i < n - 1; i++) if(str[i] == str[i + 1] && str[i] != '?')
            pos = false;
    cout << (pos? "Yes" : "No") << endl;


    return 0;
}