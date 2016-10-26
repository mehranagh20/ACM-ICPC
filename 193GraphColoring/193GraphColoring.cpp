#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
int n;
vector<int> color, tmpVec;
pair<vector<int>, int> ans;

void solution(int node, int currInd) {
    if(node == n + 1) {
        if(ans.second < currInd) {
            ans.second = currInd;
            ans.first = tmpVec;
        }
        return;
    }

    bool twoWay = true;
    for(auto &e : graph[node]) {
        if(color[e] == 1) {
            twoWay = false;
            break;
        }
    }
    if(twoWay) {
        color[node] = 1;
        tmpVec[currInd] = node;
        solution(node + 1, currInd + 1);

        color[node] = 2;
        solution(node + 1, currInd);
    }
    else {
        color[node] = 2;
        solution(node + 1, currInd);
    }
}

int main() {
    pair<vector<int>, int> &s = ans;
    int t, m;
    scanf("%d", &t);
    while(t--) {
        ans.second = 0;
        scanf("%d%d", &n, &m);
        graph.resize(n + 1); tmpVec.resize(n + 1, 0); color.resize(n + 1, 0);
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].push_back(b); graph[b].push_back(a);
        }
        solution(1, 1);
        printf("%d\n", ans.second - 1);
        printf("%d", ans.first[1]);
        for(int i = 2; i < ans.second; i++)
            printf(" %d", ans.first[i]);
        puts("");
        graph.clear();
        color.clear();
        tmpVec.clear();
    }
    return 0;
}