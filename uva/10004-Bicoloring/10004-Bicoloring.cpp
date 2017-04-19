//in the name of god...
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
int n;

bool solve() {
    vector<vector<int>> &g = graph;
    vector<int> color(n, 0), visited(n, 0);
    color[0] = 1;
    queue<int> queue1;
    queue1.push(0); visited[0] = 1;
    while(!queue1.empty()) {
        int node = queue1.front();
        int col = color[node] == 1 ? 2 : 1;
        queue1.pop();
        for(auto &e : graph[node]) {
            if(visited[e]) {
                if(color[e] != col)
                    return false;
                continue;
            }
            queue1.push(e);
            color[e] = col;
            visited[e] = 1;
        }
    }
    return true;
}

int main() {
    int m;
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        graph.clear();
        int a, b;
        graph.resize(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if(solve()) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

    return 0;
}