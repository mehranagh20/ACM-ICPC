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

int bfs(int s) {
    int ans = 1, tmp = 1;
    queue<int> queue1; queue1.push(s);
    color[s] = 0;
    bool isBipartite = true;
    while(isBipartite && !queue1.empty()) {
        int top = queue1.front(); queue1.pop();
        for(auto &e : graph[top]) {
            if(color[e] == -1) {
                tmp++;
                color[e] = 1 - color[top];
                if(color[e] == 0) ans++;
                queue1.push(e);
            }
            else if(color[e] == color[top]) {
                isBipartite = false; break;
            }
        }
    }
    if(!isBipartite) return -1;
    return ans > tmp - ans ? tmp - ans : ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int m, nod1, nod2; cin >> n >> m;
        graph.clear(); graph.resize(n);
        for(int i = 0; i < m; i++) {
            cin >> nod1 >> nod2;
            graph[nod1].push_back(nod2);
            graph[nod2].push_back(nod1);
        }
        int ans = 0;
        color.clear(); color.resize(n, -1);
        for(int i = 0; i < n; i++)
            if(color[i] == -1) {
                int tmp = bfs(i);
                if(tmp == -1) {
                    ans = -1;
                    break;
                }
                ans += tmp == 0 ? 1 : tmp;
            }
        cout << ans << endl;
    }

    return 0;
}