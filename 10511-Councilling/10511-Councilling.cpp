//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector<string> vs;
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
vector<vector<iii>> graph;

bool dinic_bfs() {
    dist.clear(); dist.resize(n, -1); dist[s] = 0;
    queue<int> queue1; queue1.push(s);
    while(!queue1.empty()) {
        int u = queue1.front(); queue1.pop();
        for(auto &e : graph[u]) {
            if(dist[e.first] != -1 || e.second.first <= 0) continue;
            dist[e.first] = dist[u] + 1;
            queue1.push(e.first);
        }
    }
    return (dist[t] != -1);
}

int dinic_dfs(int u, int f) {
    if(u == t) return f;
    for(int &i = work[u]; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        auto &e = graph[u][i].second;
        if(e.first <= 0) continue;
        if(dist[u] + 1 == dist[v]) {
            int df = dinic_dfs(v, min(f, e.first));
            if(df > 0) {
                graph[v][e.second].second.first += df;
                e.first -= df;
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

int main() { //change parties to t cap.
    int tc; cin >> tc;
    cin.get(); cin.get();
    s = 0, t = 1;
    for(int i = 0; i < tc; i++) {
        if(i) cout << endl;
        graph.clear(); graph.resize(2);
        string str;
        map<string, int> cl, parties, per;
        vs names;
        int ind = 2;
        while(getline(cin, str) && !str.empty()) {
            stringstream ss(str); ss >> str;
            graph.push_back(viii());
            per[str] = ind++; names.push_back(str);
            int curr = ind - 1;
            ss >> str;
            if(parties.find(str) == parties.end()) {
                graph.push_back(viii());
                parties[str] = ind++; names.push_back(str);
            }
            int pa = parties[str];
            graph[curr].push_back(iii(pa, ii(1, graph[pa].size())));
            graph[pa].push_back(iii(curr, ii(0, graph[curr].size() - 1)));
            while(ss >> str) {
                if(cl.find(str) == cl.end()) {
                    graph.push_back(viii());
                    graph[s].push_back(iii(ind, ii(1, graph[ind].size())));
                    graph[ind].push_back(iii(s, ii(0, graph[s].size() - 1)));
                    cl[str] = ind++; names.push_back(str);
                }
                int c = cl[str];
                graph[c].push_back(iii(curr, ii(1, graph[curr].size())));
                graph[curr].push_back(iii(c, ii(0, graph[c].size() - 1)));
            }
        }

        int half = (cl.size() - 1) / 2;
        for(auto it = parties.begin(); it != parties.end(); it++) {
            int id = it->second;
            graph[id].push_back(iii(t, ii(half, graph[t].size())));
            graph[t].push_back(iii(id, ii(0, graph[id].size() - 1)));
        }

        n = graph.size();
        int mx = maxFlow();
        if(mx == cl.size()) {
            for(auto it = cl.begin(); it != cl.end(); it++) {
                int id = it->second, ans;
                for(auto &e : graph[id]) if(e.first != s) {
                        if(graph[e.first][e.second.second].second.first > 0) {
                            ans = e.first; break;
                        }
                    }
                cout << names[ans - 2] << " " << it->first << endl;
            }
        }
        else cout << "Impossible.\n";
    }

    return 0;
}