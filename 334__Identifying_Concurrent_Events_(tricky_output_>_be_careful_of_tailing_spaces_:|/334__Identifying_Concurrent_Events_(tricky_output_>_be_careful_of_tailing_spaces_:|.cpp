//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

#define inf 1000000000
#define eps 1e-9

void floyd(vvi &adjMat, int m) {
    for(int k = 0; k < m; k++) for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
                adjMat[i][j] |= (adjMat[i][k] & adjMat[k][j]);
}

int main() {
    int tc = 0, nc;
    while(cin >> nc && nc) {
        map<string, int> mp;
        vector<string>rvMp;
        int ind = 0;
        vvi graph(200, vi(200, 0));
        for(int i = 0; i < nc; i++) {
            int n; cin >> n;
            vi tmp(n);
            for(int i = 0; i < n; i++) {
                string tmpStr; cin >> tmpStr;
                mp[tmpStr] = ind++;
                tmp[i] = ind - 1;
                rvMp.push_back(tmpStr);
            }
            for(int i = 0; i < n - 1; i++) graph[tmp[i]][tmp[i + 1]] = 1;
        }
        int emails; cin >> emails;
        for(int i = 0; i < emails; i++) {
            string a, b; cin >> a >> b;
            graph[mp[a]][mp[b]] = 1;
        }
        floyd(graph, ind);
        vii pai;
        for(int i = 0; i < ind; i++) for(int j = 0; j < ind; j++) {
                if(i == j) continue;
                if(!graph[i][j] && !graph[j][i]) {
                    pai.push_back(ii(i, j));
                    graph[i][j] = graph[j][i] = 1;
                }
            }
        cout << "Case " << ++tc <<", ";
        if(pai.size() == 0) cout << "no concurrent events.\n";
        else {
            cout << pai.size() << " concurrent events:\n";
            cout << "(" << rvMp[pai[0].first] << "," << rvMp[pai[0].second] << ") ";
            if(pai.size() > 1)
                for(int i = 1; i < 2; i++)  cout << "(" << rvMp[pai[i].first] << "," << rvMp[pai[i].second] << ") ";
            cout << endl;
        }
    }

    return 0;
}
