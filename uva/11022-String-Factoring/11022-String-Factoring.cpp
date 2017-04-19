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

string str;
vvi memo;

int solve(int i, int j) {
    if(i == j) return 1;
    if(memo[i][j] != inf) return memo[i][j];
    for(int k = i; k < j; k++) {
        int f = solve(i, k), s = solve(k + 1, j);
        bool same = true;
        int l1 = k - i + 1, l2 = j - k;
        if(l1 > l2) {
            same = l1 % l2 == 0;
            if(same) {
                int r = i, d = k + 1;
                while(r <= k) {
                    if(str[r] != str[d]) {
                        same = false;
                        break;
                    }
                    r++, d++;
                    if(d > j) d = k + 1;
                }
            }
        }
        else {
            same = l2 % l1 == 0;
            if(same) {
                int r = k + 1, d = i;
                while(r <= j) {
                    if(str[r] != str[d]) {
                        same = false;
                        break;
                    }
                    r++, d++;
                    if(d > k) d = i;
                }
            }
        }
        int now = same ? f : f + s;
        memo[i][j] = min(memo[i][j], now);
    }
    return memo[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    while(getline(cin, str) && cin && str != "*") {
        memo.assign(str.size() + 1, vi(str.size() + 1, inf));
        cout << solve(0, str.size() - 1) << endl;
    }


    return 0;
}
