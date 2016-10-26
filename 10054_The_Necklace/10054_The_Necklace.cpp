//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int > vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

vvii graph;
list<ii> cyc;

void EulerTour(list<ii>::iterator i, int u) {
    for (int j = 0; j < (int)graph[u].size(); j++) {
        ii &v = graph[u][j];
        if (v.second) {
            v.second = 0;
            for (int k = 0; k < (int)graph[v.first].size(); k++) {
                ii &uu = graph[v.first][k];
                if (uu.first == u && uu.second) {
                    uu.second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i, ii(u, v.first)), v.first);

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        if(i > 1) cout << endl;
        int n; cin >> n;
        graph.clear(); graph.resize(51);
        vii nodes;
        int st;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            st = a;
            graph[a].push_back(ii(b, 1)), graph[b].push_back(ii(a, 1));
        }
        bool poss = true;
        cout << "Case #" << i << endl;
        for(int i = 0; i < 51; i++) if(graph[i].size() & 1) {
                poss = false;
                break;
            }
        cyc.clear();
        EulerTour(cyc.begin(), st);
        vi tmp;
        if(poss) {
            for(auto e = cyc.rbegin(); e != cyc.rend(); e++) cout << (*e).first << " " << (*e).second << endl;
        }
        else cout << "some beads may be lost\n";

    }

    return 0;
}