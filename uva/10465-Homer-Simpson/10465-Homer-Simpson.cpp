//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define inf 1000000000
#define eps 1e-9

vi memo;
vii mem;
int m, n;

int poss(int t) {
    if(t < 0) return -inf;
    if(t == 0) return 0;
    if(memo[t] != -inf) return memo[t];
    if(t >= m) memo[t] = poss(t - m) + 1;
    if(t >= n) memo[t] = max(memo[t], poss(t - n) + 1);
    return memo[t];
}

ii solve(int t) {
    if(t < 0) return make_pair(-inf, inf);
    if(t < m && t < n) return make_pair(0, t);
    if(mem[t].first != -inf) return mem[t];
    ii tmp = solve(t - m), ans = {-inf, inf};
    if(tmp.second < ans.second || (tmp.second == ans.second && tmp.first + 1 > ans.first)) {
        ans = tmp; ans.first += 1;
    }
    tmp = solve(t - n);
    if(tmp.second < ans.second || (tmp.second == ans.second && tmp.first + 1 > ans.first)) {
        ans = tmp; ans.first += 1;
    }
    return mem[t] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    while(cin >> m >> n >> t) {
        memo.clear(); memo.resize(t + 10, -inf);
        int p = poss(t);
        if(p > 0) cout << p << endl;
        else {
            mem.clear(); mem.resize(t + 10, make_pair(-inf, inf));
            ii ans = solve(t);
            cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}
