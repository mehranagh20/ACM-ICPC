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
int n, m;
vvi AdjList;

vi match, vis;
// global variables
int Aug(int l) {
// return 1 if an augmenting path is found
    if (vis[l]) return 0;
// return 0 otherwise
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
        if (match[r] == -1 || Aug(match[r])) {
        match[r] = l;
        return 1;
    // found 1 matching
    } }
    return 0;
// no matching
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    vii indToEd(m);
    map<ii, int> mp;
    AdjList.clear();
    vvi graph(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(mp.find(ii(a, b)) == mp.end() && mp.find(ii(b, a)) == mp.end()) {
            mp[ii(a, b)] = mp[ii(b, a)] = indToEd.size();
            indToEd.push_back(ii(a, b));
            graph[a - 1].push_back(b - 1);
        }
    }
    AdjList.assign(indToEd.size() * 2, vi());
    for(auto &e: indToEd) {
        for(auto &ee: graph[e.first]) {
            if(ee == e.second) continue;
            int a = mp[e], b = mp[ii(ee, e.first)];
            AdjList[a].push_back(b + inToEn.size()), AdjList[b].push_back(a + indToEn.size());
        }
        for(auto &ee: graph[e.second]) {
            if(ee == e.first) continue;
            int a = mp[e], b = mp[ii(ee, e.second)];
            AdjList[a].push_back(b + inToEn.size()), AdjList[b].push_back(a + inToEn.size());
        }
    }
    cout << "edges are: \n";
    for(auto &e: indToEd) cout << e.first << " " << e.second << endl;

    cout << "\n AdjList is:\n";
    for(int i = 0; i < AdjList.size(); i++) for(auto &e: AdjList[i]) cout << i << " " << e << endl;

    int MCBM = 0;
    match.assign(V, -1);
    for (int l = 0; l < n; l++) {
        vis.assign(n, 0);
        MCBM += Aug(l);
    }
    printf("Found %d matchings\n", MCBM);

    return 0;
}
