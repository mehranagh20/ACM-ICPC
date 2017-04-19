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

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        string str;
        int k, ans = 0, pos = 1;
        cin >> str >> k;
        for(int i = 0; i < str.size() - k + 1; i++)
            if(str[i] == '-') {
                for(int j = i; j < i + k; j++)
                    str[j] = (str[j] == '+' ? '-' : '+');
                ans++;
            }
        for(int i = 0; i < str.size(); i++) if(str[i] == '-')
            pos = 0;
        cout << "Case #" << i << ": ";
        if(pos) cout << ans << endl;
        else cout << "IMPOSSIBLE\n";

    }


    return 0;
}
