//In The Name Of God
#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define eps 1e-8

//In DP, there is bottom up version and there is up-down version,,, understand the differences, you can not combine them :| be carefull

int start, n; // initialize before function
int early = -inf;
vector<vector<int>> dist, memo;
vector<pair<int, int>> price;

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
    if(bitmask == (1 << n) - 1)
        return -dist[pos][0];
    if (memo[pos][bitmask] != -inf)
        return memo[pos][bitmask];
    int &ans = memo[pos][bitmask];
    ans = -dist[pos][0];
    for (int nxt = 0; nxt < n; nxt++) // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = max(ans, price[nxt].second - dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask];
}

void floyd(vector<vector<int>> &AdjMat, int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

int main() {
    ios::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        early = -inf;
        dist.clear(); price.clear();
        int nn, m, v;
        cin >> nn >> m;
        vector<vector<int>> adj(nn + 1, vector<int>(nn + 1, inf));
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            double cost; cin >> cost;
            int w = 100 * (cost + eps);
            adj[a][b] = adj[b][a] = min(adj[a][b], w);
        }
        floyd(adj, nn + 1);
        cin >> v;
        price.resize(v + 1);
        price[0] = {0, 0};
        int sP = 0;
        vector<int> nums = {0};
        for (int i = 1; i <= v; i++) {
            int d1;
            double d2;
            cin >> d1 >> d2;
            price[i].first = d1; price[i].second = 100 * (d2 + eps);
            nums.push_back(price[i].first);
            sP += price[i].second;
        }
        dist.resize(v + 3, vector<int >(v + 3, 0));
        for(int i = 0; i < nn + 1; i++) adj[i][i] = 0;
        for (int i = 0; i < nums.size(); i++) for (int j = 0; j < nums.size(); j++)
                dist[i][j] = adj[nums[i]][nums[j]];
        n = nums.size(); start = 0;
        memo.clear(); memo.resize(nums.size() + 1, vector<int>(1 << (n + 1), -inf));
        int ans = tsp(0, 1);
        if(ans > 0) printf("Daniel can save $%.2lf\n", (double)(ans / 100.));
        else printf("Don't leave the house\n");
    }
    return 0;
}
