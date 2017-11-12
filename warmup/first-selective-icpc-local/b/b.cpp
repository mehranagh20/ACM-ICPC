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
    int n, k, r; cin >> n >> k >> r;
    vi tmp(n + 1, 0);
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        tmp[a] = 1;
    }
    int i = 2, j = r + 1, x = 0, f;
    for(int i = 1; i <= r; i++) {
        x += tmp[i];
        if(!tmp[i]) f = i;
    }
    int ans = 0;
    if(x < 2) {
        if(x == 1) {
            tmp[f] = 1;
            ans++;
        }
        else {
            ans = 2;
            tmp[r] = tmp[r - 1] = 1;
        }
        x = 2;
    }
    for(; j < tmp.size(); j++, i++) {
        x -= tmp[i - 1];
        x += tmp[j];
        if(!tmp[j]) f = j;
        if(x < 2) {
            tmp[f]++;
            ans++;
            x++;
        }

    }
    cout << ans << endl;


    return 0;
}
