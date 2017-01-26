// s holds the starting point of colering.
// a graph is bipartite if its set of verteces V can be partitioned into two disjoind set so every edge in graph
// is from one set to another one. (Tree is a bipartite graph, bipartite graph has no odd circles)
// answer is in isBipartite. AdjList is adjacency list representation of the graph.
// inside main()

    queue<int> q; q.push(s);
    vi color(V, inf); color[s] = 0;
    bool isBipartite = true;
    while (!q.empty() & isBipartite) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int) AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (color[v.first] == inf) {
                color[v.first] = 1 - color[u];
                q.push(v.first);
            } else if (color[v.first] == color[u]) {
                isBipartite = false;
                break;
            }
        }
    }

