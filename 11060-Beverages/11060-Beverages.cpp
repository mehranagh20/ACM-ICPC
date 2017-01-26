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

int main() {
    ios::sync_with_stdio(0);
    int n, m, tc = 1;
    while(cin >> n) {
        vvi graph(n);
        vi indegree(n, 0), vis(n, 0);
        std::priority_queue<int, std::vector<int>, std::greater<int> > pQueue;
        int ind = 0;
        map<string, int> mp;
        vector<string> mpNumToStr(n);
        string tmp1, tmp2;
        for(int i = 0; i < n; i++) {
            cin >> tmp1;
            mpNumToStr[ind] = tmp1;
            mp.insert(make_pair(tmp1, ind++));
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> tmp1 >> tmp2;
            graph[mp[tmp1]].push_back(mp[tmp2]);
            indegree[mp[tmp2]]++;
        }
        vi ts;
        for(int i = 0; i < n; i++) if(!indegree[i]) pQueue.push(i);
        while(!pQueue.empty()) {
            int top = pQueue.top();
            pQueue.pop();
            vis[top] = 1;
            ts.push_back(top);
            for(auto &e : graph[top]) {
                if(vis[e]) continue;
                indegree[e]--;
                if(!indegree[e]) pQueue.push(e);
            }
        }
        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
        for(int i = 0; i < n; i++) cout << " " << mpNumToStr[ts[i]];
        cout << "." << endl << endl;
    }

    return 0;
}
