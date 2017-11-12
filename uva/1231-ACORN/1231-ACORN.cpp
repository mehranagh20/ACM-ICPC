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
    int tc; cin >> tc;
    while(tc--) {
        int t, h, f; cin >> t >> h >> f;
        vvi acrones(t, vi(h + 1, 0));
        vi memo(h + 1, 0);
        for(int i = 0; i < t; i++) {
            int num; cin >> num;
            for(int j = 0; j < num; j++) {
                int tmp; cin >> tmp;
                acrones[i][tmp]++;
            }
        }
        for(int i = 0; i < t; i++)
            memo[h] = max(memo[h], acrones[i][h]); // base

        for(int i = h - 1; i >= 0; i--)
            for(int j = 0; j < t; j++) {
                acrones[j][i] += max(acrones[j][i + 1], (i <= h - f ? memo[i + f] : 0));
                memo[i] = max(memo[i], acrones[j][i]);
            }

        cout << memo[1] << endl;
    }
    cin >> tc; // :| defaq !?


    return 0;
}
