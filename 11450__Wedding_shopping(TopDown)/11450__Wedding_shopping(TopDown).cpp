//in the name of god...
#include <bits/stdc++.h>

int mon, c, price[25][25], memo[201][25];

using namespace std;

int solution(int money, int g) {
    if(money < 0) return -1e9;
    if(g == c) return mon - money;
    if(memo[money][g] != -1) return memo[money][g];
    int ans = -1;
    for(int i = 1; i <= price[g][0]; i++)
        ans = max(ans, solution(money - price[g][i], g + 1));
    return memo[money][g] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        memset(memo, -1, sizeof memo);
        cin >> mon >> c;
        for(int i = 0; i < c; i++) {
            cin >> price[i][0];
            for(int j = 1; j <= price[i][0]; j++) cin >> price[i][j];
        }
        int ans = solution(mon, 0);
        if(ans < 0) cout << "no solution" << endl;
        else cout << ans << endl;
    }
    return 0;
}