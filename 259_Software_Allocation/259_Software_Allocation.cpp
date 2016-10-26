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
vvi rem;
vi par;
int s, t, f;

void augment(int v, int minEdge) {
    if(v == s) {
        f = minEdge; return;
    }
    if(par[v] != -1) {
        augment(par[v], min(minEdge, rem[par[v]][v]));
        rem[par[v]][v] -= f; rem[v][par[v]] += f;
    }
}

int main() {
    while(true) {
        s = 36, t = 37;
        int totalUsers = 0;
        rem.clear(); rem.resize(38, vi(38, 0));
        vvi graph(38); //36 is the source and 37 is the des.
        for(int i = 0; i < 10; i++) {
            graph[i].push_back(t);
            graph[t].push_back(i);
            rem[i][t] = 1;
        }
        string str;
        while(getline(cin, str) && cin && !str.empty()) {
            graph[s].push_back(str[0] - 55);
            graph[str[0] - 55].push_back(s);
            rem[s][str[0] - 55] = str[1] - '0';
            totalUsers += str[1] - '0';
            for(int i = 3; i < str.size() - 1; i++) {
                graph[str[0] - 55].push_back(str[i] - '0');
                graph[str[i] - '0'].push_back(str[0] - 55);
                rem[str[0] - 55][str[i] - '0'] = 1;
            }
        }
        int maxFlow = 0;
        while(1) {
            f = 0;
            bitset<38> vis; vis[s] = 1;
            queue<int> queue1; queue1.push(s);
            par.clear(); par.resize(38, -1);
            while(!queue1.empty()) {
                int u = queue1.front(); queue1.pop();
                if(u == t) break;
                for(auto &e : graph[u]) {
                    if(rem[u][e] > 0 && !vis[e]) {
                        vis[e] = 1; queue1.push(e); par[e] = u;
                    }
                }
            }
            augment(t, inf);
            if(!f) break;
            maxFlow += f;
        }
        if(maxFlow == totalUsers) {
            vi comp(10, 0);
            for(int i = 0; i < 10; i++) for(int j = 10; j < 36; j++) if(rem[i][j] > 0) {
                        comp[i] = j + 55;
                        break;
                    }
            for(auto &e : comp) {
                if(e == 0) cout << '_';
                else cout << (char)e;
            }
            cout << endl;
        }
        else cout << "!" << endl;

        if(!cin) break;
    }

}
