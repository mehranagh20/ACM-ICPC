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

void polyDevision(vi &poly, int k) {
    while(true) {
        int n = -1;
        for(int i = poly.size() - 1; i >= 0; i--)
            if(poly[i]) {
                n = i;
                break;
            }
        if(n == -1 || n < k) break;
        int t = n - k;
        poly[t] += -poly[n], poly[n] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    while(cin >> n >> k && (n != -1 || k != -1)) {
        vi coefs(n + 1, 0);
        for(int i = 0; i < n + 1; i++) cin >> coefs[i];
        polyDevision(coefs, k);
        int d = 0;
        for(int i = coefs.size() - 1; i >= 0; i--) if(coefs[i]) {
                d = i; break;
            }
        for(int i = 0; i <= d; i++) {
            if(i) cout << " ";
            cout << coefs[i];
        }
        cout << endl;
    }


    return 0;
}