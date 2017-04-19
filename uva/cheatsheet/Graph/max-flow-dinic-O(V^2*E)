//Dinic network max flow algorithm, runs in O(V^2*E) time.
//efficient for graph with lots of edges.

vi dist, work;
int s, t, n; //fill s, t, n in main ---> s is start, t is destination and n is number of nodes in graph. 
vvi rem, graph; //fill graph in main. graph is adjList. also fill rem where it keeps capacity of edjes in n * n space.
//it is possible to use rem to construct the path. if there was a path from i to j then rem[j][i] > 0
//if rem[j][i] = 0 before running Dinic's so it can change with questions...

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
