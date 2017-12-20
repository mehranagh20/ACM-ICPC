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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back


vi p, h;

ll mod = 1e9 + 21;

void calc_hash(string &str) {
    p.assign(str.size() + 100, 1), h.assign(str.size() + 100, 0);
    for(int i = 1; i <= str.size(); i++) {
        h[i] = (h[i - 1] * 10 + str[i - 1] - '0') % mod;
        p[i] = (p[i - 1] * 10) % mod;
        h[i] = (h[i] + mod) % mod;
        p[i] = (p[i] + mod) % mod;
    }
}

ll sub_hash(int a, int b) {
    if(b >= h.size()) {
        cout << "wtf" << endl;
        exit(0);
    }
    return (h[b] - h[a - 1] * p[b - a + 1]) % mod;
}

bool check(int a, int b, int c, string &str) {
    if(a + b + c != str.size()) return false;
    if(a <= 0 || b <= 0 || c <= 0) return false;
    if(str[0] == '0' && a > 1) return false;
    if(str[a] == '0' && b > 1) return false;
    if(str[a + b] == '0' && c > 1) return  false;
    ll h1 = sub_hash(1, a);
    ll h2 = sub_hash(a + 1, a + b);
    ll h3 = sub_hash(a + b + 1, a + b + c);
    h1 = (h1 + mod) % mod, h2 = (h2 + mod) % mod, h3 = (h3 + mod) % mod;
    if((h1 + h2) % mod == h3) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    string str; cin >> str;
    calc_hash(str);
    int n = str.size();
    for(int i = 1; i < str.size() - 1; i++) {
        int c = i;
        int a = -1, b;
        if(check(n - c - c, c, c, str)) a = n - c - c, b = c;
        if(check(c, n - c - c, c, str)) a = c, b = n - c - c;
        if(check(n - c - c + 1, c - 1, c, str)) a = n - c - c + 1, b = c - 1;
        if(check(c - 1, n - c - c + 1, c, str)) a = c - 1, b = n - c - c + 1;
        if(a != -1) {
            int i = 0;
            while(a--) {
                cout << str[i];
                i++;
            }
            cout << '+';
            while(b--) {
                cout << str[i];
                i++;
            }
            cout << '=';
            while(i < str.size()) {
                cout << str[i];
                i++;
            }
            cout << endl;
        }
    }

    return 0;
}
