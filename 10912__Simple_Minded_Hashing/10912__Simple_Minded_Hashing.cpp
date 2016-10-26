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

vvvi memo;
int n, t;

int solve(int id, int rem, int curr) {
    if(id == 0)
        return (rem == 0 ? 1 : 0);
    if(rem <= 0) return 0;
    if(memo[id][rem][curr] != -1) return memo[id][rem][curr];
    ll ans = 0;
    for(int i = curr + 1; i <= 26; i++) ans += solve(id - 1, rem - i, i);
    return memo[id][rem][curr] = ans;

}

int main() {
    ios::sync_with_stdio(0);
    int tc = 1;
    while(cin >> n >> t && (t || n)) {
        cout << "Case " << tc++ << ": ";
        ll tmp = (n * (n + 1)) / 2;
        if (tmp > t) cout << 0 << endl;
        else {
            memo.clear();
            memo.resize(n + 1, vvi(t + 1, vi(27, -1)));
            cout << solve(n, t, 0) << endl;
        }
    }
    return 0;
}