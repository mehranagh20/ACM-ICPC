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

vi dist, work;
int s, t, n;
vvi rem, graph;

bool dinic_bfs() {
    dist.clear(); dist.resize(n, -1); dist[s] = 0;
    queue<int> queue1; queue1.push(s);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        for(auto &e : graph[u]) {
            if(dist[e] != -1 || rem[u][e] <= 0) continue;
            dist[e] = dist[u] + 1;
            queue1.push(e);
        }
    }
    return (dist[t] != -1);
}

int dinic_dfs(int u, int f) {
    if(u == t) return f;
    for(int &i = work[u]; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(rem[u][v] <= 0) continue;
        if(dist[u] + 1 == dist[v]) {
            int df = dinic_dfs(v, min(f, rem[u][v]));
            if(df > 0) {
                rem[v][u] += df;
                rem[u][v] -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int result = 0;
    while(dinic_bfs()) {
        work.clear(); work.resize(n, 0);
        while(int d = dinic_dfs(s, inf)) result += d;
    }
    return result;
}

int main() {
    while(true) {
        s = 36, t = 37, n = 38;
        int totalUsers = 0;
        rem.clear(); rem.resize(38, vi(38, 0));
        graph.clear(); graph.resize(38); //36 is the source and 37 is the des.
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

        int ma = maxFlow();

        if(ma == totalUsers) {
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


    return 0;
}
