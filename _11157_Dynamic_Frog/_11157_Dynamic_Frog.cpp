//in the name of god...
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n, d, ans, last = 0;
        cin >> n >> d;
        vector<pair<int, int>> dis(n);
        char c, cc;
        int num;
        for(int i = 0; i < n; i++) {
            cin >> c >> cc;
            cin >> num;
            if(c == 'S') dis[i] = make_pair(num, 0);
            else dis[i] = make_pair(num, 1);
        }
        vector<int> visited(n, 0);
        ans = dis[0].first;
        for(int i = 0; i < n; i++) {
            if(dis[i].second) {
                ans = max(ans, dis[i].first - last);
                last = dis[i].first;
            }
            else {
                if(i == n - 1) {
                    ans = max(ans, d - last);
                    continue;
                }
                ans = max(ans, dis[i + 1].first - last);
                last = dis[i + 1].first;
                if(!dis[i + 1].second) visited[i + 1] = 1;
                i++;
            }
        }
        last = d;
        for(int i = dis.size() - 1; i >= 0; i--) {
            if(!visited[i]) {
                ans = max(ans, last - dis[i].first);
                last = dis[i].first;
            }
        }
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}