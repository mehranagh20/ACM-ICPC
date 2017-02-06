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

bool dev(string &str, int n) {
    int m = 0, p = 1;
    for(int i = str.size() - 1; i >= 0; i--) {
        //cout << str[i] << " " << m + (str[i] - '0') * p << " " << m + (str[i] - '0') * p % n << endl;
        m = (m + (str[i] - '0') * p) % n, p = ((p % n) * (10 % n)) % n;
    }
    return m == 0;
}

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        int m; cin >> m;
        vi nums(m);
        for(auto &e : nums) cin >> e;
        bool pos = true;
        for(auto &e : nums) if(!dev(str, e)) {
            pos = false;
            break;
        }
        if(pos) cout << str << " - Wonderful." << endl;
        else cout << str << " - Simple." << endl;
    }

    return 0;
}
