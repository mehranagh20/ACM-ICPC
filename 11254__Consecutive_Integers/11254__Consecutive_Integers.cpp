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
#define eps 1e-7
#define pi 3.14159

int main() {
    ios::sync_with_stdio(0);
    long long n;
    while(cin >> n && n != -1) {
        long long l = (sqrt(1 + 8 * n) - 1) / 2;
        bool found = false;
        for(int i = l; i >= 1; i--) {
            long long tmp = n - (i * (i + 1) / 2);
            if (tmp % i == 0) {
                tmp /= i;
                cout << n << " = " << tmp + 1 << " + ... + " << i + tmp << endl;
                found = true;
                break;
            }
        }
        if(!found) cout << n << " = " << n << " + ... + " << n << endl;
    }

    return 0;
}