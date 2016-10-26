//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

vvi graph;
vi color;
int n;

bool bfs(int s) {
    queue<int> queue1; queue1.push(s);
    color[s] = 0;
    bool isBipartite = true;
    while(isBipartite && !queue1.empty()) {
        int top = queue1.front(); queue1.pop();
        for(auto &e : graph[top]) {
            if(color[e] == -1) {
                color[e] = 1 - color[top];
                queue1.push(e);
            }
            else if(color[e] == color[top]) {
                isBipartite = false; break;
            }
        }
    }
    return isBipartite;
}

int main() {
    ios::sync_with_stdio(0);
    while(cin >> n && n) {
        int nod1, nod2;
        graph.clear(); graph.resize(n);
        cin >> nod1 >> nod2;
        while(nod1 || nod2) {
            graph[nod1 - 1].push_back(nod2 - 1);
            graph[nod2 - 1].push_back(nod1 - 1);
            cin >> nod1 >> nod2;
        }
        bool isB = true;
        color.clear(); color.resize(n, -1);
        for(int i = 0; i < n; i++)
            if(color[i] == -1) {
                isB &= bfs(i);
                if(!isB) break;
            }
        if(isB) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}