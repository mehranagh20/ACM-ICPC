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
    int n, tc = 0;
    vi ans = {1};
    for(int i = 1; i < 12; i++) {
        ans.push_back(((ans.back() * 2 * (2 * i - 1)) / (i + 1)));
    }
    while(cin >> n) {
        if(tc++) cout << endl;
        cout << ans[n] << endl;
    }


    return 0;
}
