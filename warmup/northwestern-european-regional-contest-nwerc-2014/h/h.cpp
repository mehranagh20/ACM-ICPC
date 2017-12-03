//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        vii a(n);
        vvi graph(n);
        for (int i = 0; i < n - 1; ++i) {
            int b, c; cin >> b >> c;
            graph[b - 1].push_back(c - 1);
            graph[c - 1].push_back(b - 1);
        }
        a[0] = ii(1, 2);
        queue<int> q; q.push(0);
        vi vis(n, 0); vis[0] = 1;
        int k = 3;
        while(q.size()) {
            int u = q.front(); q.pop();
            int tmp = 0;
            for(auto &e: graph[u]) if(!vis[e]) {
                    if(tmp == 0)
                        a[e].second = a[u].first;
                    else a[e].second = a[u].second;
                    if(graph[e].size() == 1) a[e] = a[u];
                    else
                        a[e].first = k++;
                    tmp = 1 - tmp;
                    vis[e] = 1;
                    q.push(e);
                }
        }
        for(auto &e: a) cout << e.first << " " << e.second << endl;
    }


    return 0;
}
