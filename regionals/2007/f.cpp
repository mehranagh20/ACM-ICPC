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
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
vvii AdjList;
vvi graph;

void tarjanSCC(int u, set<vi> &cur) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0)
            tarjanSCC(v.first, cur);
        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        vi tmp;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            tmp.push_back(v);
            if (u == v) break; }
        cur.insert(tmp);
    } }

// inside int main()
int main() {
    int n;
    while(cin >> n && n) {
        map<string, int> mp;
        vs ntos;
        AdjList.assign(n, vii());
        while(getchar() != '\n') continue;
        for(int i = 0; i < n; i++) {
            string l; getline(cin, l);
            stringstream ss(l);
            string cur; ss >> cur;
            if(mp.find(cur) == mp.end()) {
                mp[cur] = ntos.size();
                ntos.push_back(cur);
            }
            while(ss >> l) {
                if(mp.find(l) == mp.end()) {
                    mp[l] = ntos.size();
                    ntos.push_back(l);
                }
                int a = mp[cur], b = mp[l];

                if(find(AdjList[b].begin(), AdjList[b].end(), ii(a, 0)) == AdjList[b].end())
                    AdjList[b].push_back(ii(a, 0));
            }

        }
        int V = AdjList.size();
        dfs_num.assign(V, 0); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        vvi sccs;
        set<vi> ss;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == 0)
                tarjanSCC(i, ss);
        si all;
        for(auto &e: ss) sccs.push_back(e);
        graph.assign(sccs.size(), vi());
        for(int i = 0; i < sccs.size(); i++) {
            if(sccs[i].size() > 1) all.insert(i);

            for(int j = 0; j < sccs[i].size(); j++) {
                for(auto &e: AdjList[sccs[i][j]]) {
                    for(int k = 0; k < sccs.size(); k++) if(k != i) {
                            bool found = false;
                            for(int d = 0; d < sccs[k].size(); d++) if(sccs[k][d] == e.first) {
                                    graph[k].push_back(i);
                                    found = true;
                                    break;
                                }

                            if(found) break;
                        }
                }
            }
        }
        vs tmp;
        while(true) {
            bool found = false;
            for(auto &e: all) {
                for(auto &ee: graph[e]) if(all.find(ee) == all.end()){
                    found = true;
                    all.insert(ee);
                }
            }

            if(!found) break;
        }

        for(auto &e: all) for(auto &ee: sccs[e]) tmp.push_back(ntos[ee]);


        sort(tmp.begin(), tmp.end());
        cout << tmp.size() << endl;
        cout << tmp[0];
        for(int i = 1; i < tmp.size(); i++) cout << " " << tmp[i];
        cout << endl;
    }

}
