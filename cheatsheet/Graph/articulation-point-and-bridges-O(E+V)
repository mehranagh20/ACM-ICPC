// this alg finds bridges and articulation points of graph.
// removal of articulation vertex or bridge edge cause graph to become two disconnected part.


// fill these global vars as shown below in the main before calling this func.
// bridges are not saved and are shown in the function, process them as you want.
//articulation points are in articulation_vertex in main.

vi dfs_low, dfs_num, dfs_parent, articulation_vertex;
vvii AdjList;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0) { // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; 
            if (dfs_low[v.first] > dfs_num[u]) // found a bridge
                ;// bridges are here, use them as you want.
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    } }


// inside int main()
// n is number of verteces.

    dfsNumberCounter = 0; dfs_num.assign(n, 0); dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0); articulation_vertex.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (dfs_num[i] == 0) {
            dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case

