//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define inf 1000000000
#define eps 1e-8

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, ans = 0; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        for(int i = 0; i < n; i++) for(int j = 0; j < n - 1; j++) {
                if(v[j] > v[j + 1]) {
                    ans++;
                    swap(v[j], v[j + 1]);
                }
            }
        cout << "Optimal train swapping takes " << ans << " swaps." << endl;
    }

    return 0;
}