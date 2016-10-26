//In The Name Of God
#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
int n;
vector<vector<int>> memo; // used to memorize the states
vector<pair<int, int>> coinValue;

int change(int &value, int f, int s) {
    int num = f * f + s * s;
    if(num == value * value) return 0;
    if (f >= value || s >= value) return inf;
    if (memo[f][s] != inf) return memo[f][s];
    for (int i = 0; i < n; i++)
        memo[f][s] = min(memo[f][s], change(value, f + coinValue[i].first, s + coinValue[i].second));
    return memo[f][s] += 1;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        memo.clear(); memo.resize(m + 10, vector<int>(m + 10, inf));
        coinValue.resize(n);
        for(int i = 0; i < n; i++) cin >> coinValue[i].first >> coinValue[i].second;
        int l = change(m, 0, 0);
        if(l < inf) printf("%d\n", l);
        else printf("not possible\n");
    }

    return 0;
}