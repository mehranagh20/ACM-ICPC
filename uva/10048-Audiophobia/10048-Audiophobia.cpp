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
vector<pair<int, ii>> edges;
vvii graph;
int ans, des;

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

int kruskal() {
    int cost = 0;
    for(int i = 0; i < edges.size(); i++) {
        pair<double, ii> fr = edges[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            graph[fr.second.second].push_back(make_pair(fr.second.first, fr.first));
            graph[fr.second.first].push_back(make_pair(fr.second.second, fr.first));
            cost += fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m, q, tc = 0;
    while(cin >> n >> m >> q && (m || n || q)) {
        if(tc++) cout << endl;
        buildUfds(n);
        edges.clear();
        for(int i = 0; i < m; i++) {
            int a, b, d; cin >> a >> b >> d;
            edges.push_back(make_pair(d, make_pair(a - 1, b - 1)));
        }
        sort(edges.begin(), edges.end());
        graph.clear(); graph.resize(n);
        kruskal();
        cout << "Case #" << tc << endl;
        vvi memo(n, vi(n, -1));
        for(int i = 0; i < q; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            if(memo[a][b] != -1) {
                if(memo[a][b] == -2) cout << "no path\n";
                else cout << memo[a][b] << endl;
            }
            else if(memo[b][a] != -1) {
                if(memo[b][a] == -2) cout << "no path\n";
                else cout << memo[b][a] << endl;
            }
            else {
                des = b; ans = -inf;
                vis.clear(); vis.resize(n, 0);
                dfs(a);
                if (ans != -inf) {
                    cout << ans << endl;
                    memo[a][b] = memo[b][a] = ans;
                }
                else {
                    cout << "no path\n";
                    memo[a][b] = memo[b][a] = -2;
                }
            }
        }
    }
    return 0;
}