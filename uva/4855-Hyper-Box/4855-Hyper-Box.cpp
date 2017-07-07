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

    vector<unsigned long long> coinValue = {1, 2};
    while(coinValue.back() < 2000000000)
        coinValue.push_back(coinValue.back() + coinValue[coinValue.size() - 2]);
    int n = coinValue.size();
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        int nn; cin >> nn;
        ll ans = 1;
        for(int i = 0; i < nn; i++) {
            ull tmp; cin >> tmp;
            int num = 0;
            for(int i = coinValue.size() - 1; i >= 0; i--) {
                if(tmp >= coinValue[i]) tmp -= coinValue[i], num++;
            }
            ans *= num;

        }
        cout << ans << endl;
    }


    return 0;
}
