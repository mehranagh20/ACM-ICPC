//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 230584300900000000
#define eps 1e-8

int main() {
    ios::sync_with_stdio(0);
    ll n;
    while(cin >> n && n) {
        ll mx = inf;
        for(int i = 0; i < 33; i++) {
            ll tmp = pow(2, i);
            for (int j = 0; j < 21; j++) {
                ll tmp2 = pow(3, j);
                if (tmp * tmp2 < mx && tmp * tmp2 >= n) {
                    mx = tmp * tmp2;
                    break;
                }
            }
        }
        cout << mx << endl;
    }

    return 0;
}