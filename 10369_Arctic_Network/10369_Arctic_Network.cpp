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

double kruskal(int k) {
    double ans;
    for(int i = 0; i < edges.size() && n > k; i++) {
        pair<double, ii> fr = edges[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            n--;
           // graph[fr.second.second].push_back(make_pair(fr.second.first, fr.first));
            //graph[fr.second.first].push_back(make_pair(fr.second.second, fr.first));
            ans = fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int k; cin >> k >> n;
        vii coor(n);
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            coor[i].first = a; coor[i].second = b;
        }
        edges.clear();
        for(int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
                double dis = sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2));
                edges.push_back(make_pair(dis, make_pair(i, j)));
            }
        sort(edges.begin(), edges.end());
        buildUfds(n);
        cout << fixed << setprecision(2) << kruskal(k) << endl;
    }

    return 0;
}