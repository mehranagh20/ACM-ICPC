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
    int n;  cin >> n;
    vi nums(n), need(n, 0);
    for(auto &e: nums) cin >> e;
    string str; cin >> str;
    bool ok = true;
    int c = 0;
    for(int i = 0; i < n; i++) {
        int t = nums[i] - 1;
        if(t > i) {
            if(i > c) c = i;
            for (int j = c; j < t; ++j) {
                need[j] = 1;
            }
            if(t > c)
                c = t;
        }
    }
    for(int i = 0; i < n; i++) if(need[i] && str[i] == '0')
            ok = false;
    cout << (ok? "YES" : "NO") << endl;


    return 0;
}