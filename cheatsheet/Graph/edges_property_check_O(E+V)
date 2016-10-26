// we consider three states for running dfs: 1. unvisited, visited(visited and completed), explored(visited but not completed)
// Graph Edges are classified into three types:
// 1) tree edge: explored to unvisited.
// 2) back edge: explored to explored, an edge which goes back to a vertecs that is not completed yet. Found Circle Here.
// 3) forward/Cross edges: explored to visited, goes to a vertecs which is completly visited.


vi dfs_num, dfs_parent; // fill dfs_num in main with size of verteces and value of 0, allocate size of verteces
// for dfs_parent, in main call this func for every unvisited verteces.
vvii AdjList; // holds edges.

// function is raw and should be filled with desiered actions.

void graphCheck(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0) { // Tree Edge, EXPLORED->UNVISITED
            dfs_parent[v.first] = u; // parent of this children is me
            graphCheck(v.first);
        }
        else if (dfs_num[v.first] == 1) { // EXPLORED->EXPLORED
            if (v.first == dfs_parent[u]); // biconditional edge, usually is not considered as circle
                
            else // back edge, circle
                ;
        }
        else if (dfs_num[v.first] == 2) // EXPLORED->VISITED, forward edge
        ;
    }
    dfs_num[u] = 2; // Complete
} 
