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

vector<int> ufds;
vi ufds2, ufds3;
int n, m;

void buildUfds(int n) {
    ufds.clear(); ufds.resize(n);
    for(int i = 0; i < n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : findSet(ufds[i]);
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

int ans, kk = 0;

int kruskal(viii &graph) {
    for(int i = 0; i < ufds.size(); i++) {
        ufds2[i] = ufds[i];
        ufds[i] = i;
    }
    int cost = 0;
    for(int i = 0; i < graph.size(); i++) {
        pair<int, ii> fr = graph[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            kk++;
            cost += fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    for(int i = 0; i < ufds.size(); i++) ufds[i] = ufds2[i];
    return cost;
}

vi sel;
viii edges;
void backtrack(int k, int all) {
    if(k >= m) return;
    if(all == n - 1) {
        int cur = 0;
        viii cur_edges;
        for(int i = 0; i < m; i++) {
            if(sel[i]) cur += edges[i].first;
            else cur_edges.push_back(edges[i]);
        }
        k = 0, kk = 0;
        sort(cur_edges.begin(), cur_edges.end());
        int now = kruskal(cur_edges);
        if(kk == n - 1) ans = min(ans, cur + now);
    }
    else {
        int a = edges[k].second.first, b = edges[k].second.second;
        if(!isSameSet(a, b)) {
            int a_parent = findSet(a), b_parent = findSet(b);
            joinSets(a, b);
            sel[k] = 1;
            backtrack(k + 1, all + 1);
            ufds[a_parent] = a_parent;
            ufds[b_parent] = b_parent;
            sel[k] = 0;
        }
        backtrack(k + 1, all);
    }
}

int main() {
    ios::sync_with_stdio(0);

    while(cin >> n && n) {
        ufds2.assign(10, 0), ufds3.assign(10, 0);
        buildUfds(n);
        cin >> m;
        edges.assign(m, iii(0, ii(0, 0)));
        for(auto &e: edges) {
            cin >> e.second.first >> e.second.second >> e.first;
            e.second.first--, e.second.second--;
        }
        sel.assign(m, 0);
        ans = inf;
        backtrack(0, 0);
        if(ans == inf) cout << "No way!" << endl;
        else cout << ans << endl;
    }

    return 0;
}
