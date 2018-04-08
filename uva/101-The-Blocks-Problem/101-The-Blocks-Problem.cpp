//In The Name Of God
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define inf 1000000000

vvi memo, dist;
int start, n; // initialize before function

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
    if (bitmask == (1 << (n)) - 1)
        return dist[pos][start]; // return trip to close the loop
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int ans = inf;
    for (int nxt = 0; nxt < n; nxt++) // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}


int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        pair<int, int> xy; cin >> xy.first >> xy.second;
        cin >> xy.first >> xy.second;
        vector<pair<int, int>> coor;
        cin >> n;
        coor.resize(n + 2); coor[0] = xy;
        for(int i = 1; i <= n; i++) cin >> coor[i].first >> coor[i].second;
        dist.resize(n + 2, vi(n + 2, 0));
        for(int i = 0; i < n + 1; i++) for(int j = 0; j < n + 1; j++)
                dist[i][j] = abs(coor[i].first - coor[j].first) + abs(coor[i].second - coor[j].second);
        memo.clear(); memo.resize(n + 2, vi(1 << (n + 2), -1));
        start = 0; n++;
        printf("The shortest path has length %d\n", tsp(0, 1));
        dist.clear(); coor.clear();
    }
    return 0;
}