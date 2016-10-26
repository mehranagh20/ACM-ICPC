#include <bits/stdc++.h>

using namespace std;

int main() {
    int i = 1;
    while(true) {
        vector<int> tmp(101, 0);
        vector<vector<int>> con(100), dis(101, tmp);
        int a, b;
        scanf("%d%d", &a, &b);
        if(!a && !b)
            break;
        con[a - 1].push_back(b - 1);
        while(scanf("%d%d", &a, &b) && a && b) {
            con[a - 1].push_back(b - 1);
        }
        int totDis = 0, paths = 0;
        for(int i = 0; i < 100; i++) {
            if(!con[i].empty()) {
                vector<bool> vis(100, false);
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()) {
                    for(auto &e : con[q.front()]) {
                        if(!vis[e]) {
                            paths++;
                            q.push(e);
                            totDis += dis[i][q.front()] + 1;
                            dis[i][e] = dis[e][i] = dis[i][q.front()] + 1;
                            vis[e] = true;
                        }
                    }
                    q.pop();
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",i++, (float)totDis / paths);
    }

    return 0;
}

