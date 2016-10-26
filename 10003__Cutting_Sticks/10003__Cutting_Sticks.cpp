#include <bits/stdc++.h>

using namespace std;
#define inf 1e9

int memo[1001][1001], cuts[51], n, visited[51];

int solution(int l, int r) {
    if(memo[l][r]) return memo[l][r];
    int still = 0; memo[l][r] = inf;
    for(int i = 0; i < n; i++) {
        if (visited[i] || cuts[i] >= r || cuts[i] <= l)
            continue;
        still = 1;
        visited[i] = 1;
        memo[l][r] = min(memo[l][r], solution(l, cuts[i]) + solution(cuts[i], r));
        visited[i] = 0;
    }
    if(!still) return memo[l][r] = min(memo[l][r], r - l);
    return memo[l][r] += r - l;
}
int main() {
    ios::sync_with_stdio(0);
    int l;
    while(cin >> l && l) {
        cin >> n;
        if (!n) {printf("The minimum cutting is %d.\n", 0); continue;}
        memset(visited, 0, sizeof visited); memset(memo, 0, sizeof memo);
        for (int i = 0; i < n; i++) cin >> cuts[i];
        int ans = inf;
        for (int i = 0; i < n; i++) {
            visited[i] = 1;
            ans = min(ans, solution(cuts[i], l) + solution(0, cuts[i])); visited[i] = 0;
        }
        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}