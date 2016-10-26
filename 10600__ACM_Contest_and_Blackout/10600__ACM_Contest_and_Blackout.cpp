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

vi ufds, vis;
vector<pair<double, ii>> edges;
vvii graph;
int ans, des, n;

bool dfs(int i) {
    vis[i] = 1;
    if(i == des) return true;
    for(auto &e : graph[i])
        if(!vis[e.first]) if(dfs(e.first)) {
            ans = max(ans, e.second);
            return true;
        }
    return false;
}

void buildUfds(int n) {
    ufds.clear(); ufds.resize(n);
    for(int i = 0; i < n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : (ufds[i] = findSet(ufds[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

int kruskal(bool check, int off) {
    int cost = 0, e = 0;
    for(int i = 0; i < edges.size(); i++) {
        if(i == off) continue;
        pair<double, ii> fr = edges[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            e++;
            if(check) vis[i] = 1;
            cost += fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return e == n - 1 ? cost : inf;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        edges.clear();
        int m; cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            edges.push_back(make_pair(c, make_pair(a - 1, b - 1)));
        }
        sort(edges.begin(), edges.end());
        buildUfds(n);
        vis.clear(); vis.resize(edges.size(), 0);
        int first = kruskal(true, -1), sec = inf;
        for(int i = 0; i < vis.size(); i++)if(vis[i]) {
                buildUfds(n);
                sec = min(sec, kruskal(false, i));
                if(sec == first) break;
            }
        cout << first << " " << sec << endl;

    }

    return 0;
}