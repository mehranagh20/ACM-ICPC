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
        cout << "Case #" << i + 1 << ": ";
        int n; cin >> n;
        vi items(n);
        for(int i = 0; i < n; i++) cin >> items[i];
        int j = -1, ans = 0;
        sort(items.begin(), items.end());
        for(int i = n - 1; i >= 0; i--) {
            int sum = items[i];
            while(sum < 50 && j < i - 1)
                sum += items[i], j++;
            if(sum >= 50) ans++;
        }
        cout << ans << endl;
    }


    return 0;
}
