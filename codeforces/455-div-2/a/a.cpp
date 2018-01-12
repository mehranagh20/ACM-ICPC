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

class hashh {
public:
    vi p, h;
    ll mod1;
    hashh(string &str, ll pp, ll mod1 = 1e9 + 21) {
        this->mod1 = mod1;
        p.assign(str.size() + 100, 1), h.assign(str.size() + 100, 0);
        for(int i = 1; i <= str.size(); i++) {
            h[i] = (h[i - 1] * pp + str[i - 1] - '0') % mod1;
            p[i] = (p[i - 1] * pp) % mod1;
            h[i] = (h[i] + mod1) % mod1;
            p[i] = (p[i] + mod1) % mod1;
        }
    }

    ll sub_hash(int a, int b) { // 'a' and 'b' are one based and inclusive.
        ll ret = (h[b] - h[a - 1] * p[b - a + 1]) % mod1;
        return (ret + mod1) % mod1;
    }

};


bool check(int a, int b, int c, string &str, hashh &h) {
    if(a + b + c != str.size()) return false;
    if(a <= 0 || b <= 0 || c <= 0) return false;
    if(str[0] == '0' && a > 1) return false;
    if(str[a] == '0' && b > 1) return false;
    if(str[a + b] == '0' && c > 1) return  false;
    ll h1 = h.sub_hash(1, a);
    ll h2 = h.sub_hash(a + 1, a + b);
    ll h3 = h.sub_hash(a + b + 1, a + b + c);
    if((h1 + h2) % h.mod1 == h3) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    string a ,b; cin >> a >> b;
    set<string> s;
    string tmp;
    for(int i = 0; i < a.size(); i++) {
        tmp += a[i];
        for (int j = 0; j < b.size(); ++j) {
            string tmp2 = tmp;
            for(int k = 0; k <= j; k++) tmp2 += b[k];
            s.insert(tmp2);
        }
    }
    cout << *s.begin() << endl;

    return 0;
}
