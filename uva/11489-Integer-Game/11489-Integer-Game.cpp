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
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        string str; cin >> str;
        cout << "Case " << i + 1 <<": ";
        vi dig(10, 0);
        int sum = 0, nec = 0, oth = 0;
        for(auto &c : str) {
            dig[c - '0']++;
            sum += c - '0';
            if((c - '0') % 3 == 0) nec++;
            else oth++;
        }
        if(sum % 3 == 0) {
            if(oth == 1) nec++;
            if(nec & 1) cout << "S" << endl;
            else cout << "T" << endl;
        }
        else {
            int need = (sum % 3);
            for(; need < 10; need += 3) if(dig[need]) {
                need = -1, oth--;
                break;
            }
            if(oth == 1) nec++;
            if(need == -1) {
                if(nec & 1) cout << "T" << endl;
                else cout << "S" << endl;
            }
            else
                cout << "T" << endl;
        }

    }


    return 0;
}
