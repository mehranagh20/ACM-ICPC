//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
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

vvi all, memo;
int n;

ll solve(ll id, ll k) {
    //cout << id << " " << k << endl;
    if(k == 0) return 0;
    if(k < 0 || id >= n) return inf;
    if(memo[id][k] != -1) return memo[id][k];
    memo[id][k] = inf;
    for(ll i = 0; i <= k; i++)
        memo[id][k] = min(memo[id][k], all[id][i] + solve(id + 1, k - i) + i * i);
    return memo[id][k];
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        int m; cin >> n >> m;
        all.assign(n, vi());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int tmp; cin >> tmp;
                all[i].push_back(tmp);
            }
            all[i].push_back(0);
            sort(all[i].begin(), all[i].end());
            for(int j = 1; j < all[i].size(); j++) all[i][j] += all[i][j - 1];
        }
        memo.assign(n + 10, vi(n + 10, -1));
        cout << "Case #" << i + 1 << ": " << solve(0, n) << endl;
    }

    return 0;
}
