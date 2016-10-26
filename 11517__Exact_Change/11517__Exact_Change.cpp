//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define inf 1000000000
//solved this question with knapsack variation :)) it may not be that fast but it's so fast to code and figure out :)
int main() {
    ios::sync_with_stdio(0);
    int tc, value, n; cin >> tc;
    while(tc--) {
        cin >> value >> n;
        vi coinValue(n);
        for(int i = 0; i < n; i++) cin >> coinValue[i];
        vector<pair<int, int>> way(11000, make_pair(0, inf));
        pair<int, int> ans = {inf, inf};
        way[0] = make_pair(1, 0);
        for(int i = 0; i < n; i++) for(int j = 11000; j >= coinValue[i]; j--) {
                way[j].first += way[j - coinValue[i]].first;
                if(way[j - coinValue[i]].first)
                    way[j].second = min(way[j].second, way[j - coinValue[i]].second + 1);
                if((way[j].first && j < ans.first && j >= value) || way[j].first && j == ans.first && way[j].second < ans.second) {
                    ans.first = j; ans.second = way[j].second;
                }
            }
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}