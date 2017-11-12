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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int done, ans;
set<ii> st;

void solve(int rw, int ld, int rd, int col) {
    if(rw == done) {
        ans++;
        return;
    }
    int ok = done & ~(rw | ld | rd);
    while(ok) {
        int lsb = ok & -ok;
        ok -= lsb;
        if(st.find(ii(lsb, col)) == st.end())
            solve(rw | lsb, (ld | lsb) << 1, (rd | lsb) >> 1, col + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, tc = 0;
    while(cin >> n && n) {
        st.clear();
        string str;
        for(int i = 0; i < n; i++) {
            cin >> str;
            for(int j = 0; j < n; j++) if(str[j] == '*')
                st.insert(ii(1 << i, j));
        }
        done = (1 << n) - 1;
        ans = 0;
        solve(0, 0, 0, 0);
        cout << "Case " << ++tc << ": " << ans << endl;
    }


    return 0;
}
