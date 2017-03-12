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
        if(i) cout << endl;
        int a, b; cin >> a >> b;
        for(int i = 0; i < b; i++) {
            for(int i = 1; i <= a; i++) {
                for(int j = 0; j < i; j++) cout << i;
                cout << endl;
            }
            for(int i = a - 1; i >= 0; i--) {
                for(int j = 0; j < i; j++) cout << i;
                if(i) cout << endl;
            }
            if(i < b - 1) cout << endl;
        }

    }


    return 0;
}
