// In The Name Of God
#include <bits/stdc++.h>

using namespace std;

int memo[110][110];

int ways(int k, int n) {
    if(k == 1) return 1;
    if(memo[k][n] != -1) return memo[k][n];
    memo[k][n] = 0;
    for(int i = 0; i <= n; i++) {
        memo[k][n] += ways(k - 1, n - i);
        memo[k][n] %= 1000000;
    }
    return memo[k][n];
}

int main() {
    int n, k;
    memset(memo, -1, sizeof memo);
    while(cin >> n >> k && (n || k))
        cout << ways(k, n) << endl;
    return 0;
}
