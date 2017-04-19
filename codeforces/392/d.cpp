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
    ull base;
    string num; cin >> base >> num;
    ull n = num.size(), i = n - 1, cur = 1, ans = 0;
    while(i >= 0) {
        string hlp = "";
        ull k = 0, j = 1;
        ll i = num.size() - 1;
        while((k + (num[i] - '0') * j) < base) {
            hlp += num[i];
            k += (num[i] - '0') * j;
            j *= 10;
            i--;
            if(i < 0) break;
        }
        while(hlp.back() == '0' && hlp.size() > 1) i++, hlp.pop_back();
        ans += cur * k;
        cur *= base;
    }
    cout << ans << endl;


    return 0;
}
