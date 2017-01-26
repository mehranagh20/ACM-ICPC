// kahn's alg for finding a valid topological sort.
// in TopSort 'u' comes before 'v' if edge u -> v exists in DAG. 

// n is number of vertexes. indegree stores number of incoming edges to i'th vertex.
// fill n and indegree before defination of priority_queue.
// ts holds the Topsort

vi indegree(n, 0), vis(n, 0);
//calculate indegree before running alg.

vi ts;
std::priority_queue<int, std::vector<int>, std::greater<int> > pQueue; 
for(int i = 0; i < n; i++) if(!indegree[i]) pQueue.push(i);
        while(!pQueue.empty()) {
            int top = pQueue.top();
            pQueue.pop();
            vis[top] = 1;
            ts.push_back(top);
            for(auto &e : graph[top]) {
                if(vis[e]) continue;
                indegree[e]--;
                if(!indegree[e]) pQueue.push(e);
            }
        }
