//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vvi memo;
int n, k, m;

ll sol(int nn, int kk) {
    if(nn == n && kk == k) return 1;
    if(nn > n || kk > k) return 0;
    if(memo[nn][kk] != -1) return memo[nn][kk];
    ll ans = 0;
    for(int i = 1; i <= m; i++) ans += sol(nn + i, kk + 1);
    return memo[nn][kk] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n >> k >> m) {
        memo.clear(); memo.resize(51, vi(51, -1));
        cout << sol(0, 0) << endl;
    }

    return 0;
}