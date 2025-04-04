#include <bits/stdc++.h>
using namespace std;
vector<int> visited;
int v;
void bfs(vector<int> &dist, vector<vector<int>> &graph) {
    queue<int> q;
    visited.clear();
    visited.resize(v, 0);
    visited[0] = 1;
    q.push(0);
    dist.push_back(0); 
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (auto neighbour : graph[curr]) {
            if (!visited[neighbour]) { 
                q.push(neighbour);
                visited[neighbour] = 1;
                dist.push_back(neighbour); 
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    v = n;
    vector<int> dist;
    bfs(dist, adj);
    return dist;
}