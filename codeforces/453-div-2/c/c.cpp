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

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vi f(1e6, -1), s(1e6, -1);
    int ind = 0, last = 0, last_num = 0;
    bool perfect = true;
    for(int i = 0; i <= n; i++) {
        int num; cin >> num;
        for(int i = 0; i < num; i++) {
            if(last_num > 1) {
                last_num = num;
                while(num--) {
                    f[ind] = s[ind] = last;
                    ind++;
                }
                if(last_num > 1) {
                    perfect = false;
                    s[ind - 1] = last - 1;
                }
                last = ind;
            }
            else {
                last_num = num;
                while(num--) {
                    f[ind] = s[ind] = last;
                    ind++;
                }
                last = ind;
            }
        }
    }
    if(perfect) cout << "perfect" << endl;
    else {
        cout << "ambiguous" << endl;
        int i = 1;
        cout << f[0];
        while(f[i] != -1) {
            cout <<  " " << f[i];
            i++;
        }
        cout << endl;
        i = 1;
        cout << s[0];
        while(f[i] != -1) {
            cout <<  " " << s[i];
            i++;
        }
        cout << endl;
    }


    return 0;
}