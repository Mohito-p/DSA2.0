class Solution {
    public:
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          vector<vector<pair<int, int>>> adj(V + 1);
          
          for (auto edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int w = edge[2];
              adj[u].push_back({v, w});
              adj[v].push_back({u, w});
          }
  
          int src = 1;
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          vector<int> dist(V + 1, INT_MAX);
          vector<int> parent(V + 1);
  
          for (int i = 1; i <= V; i++) {
              parent[i] = i;
          }
  
          dist[src] = 0;
          pq.push({0, src});
  
          while (!pq.empty()) {
              auto it=pq.top();
              int node = it.second;
              int dis = it.first;
              pq.pop();
  
              for (auto it : adj[node]) {
                  int adjNode = it.first;
                  int edgeWeight = it.second;
  
                  if (dis + edgeWeight < dist[adjNode]) {
                      dist[adjNode] = dis + edgeWeight;
                      pq.push({dist[adjNode], adjNode});
                      parent[adjNode] = node;
                  }
              }
          }
  
          if (dist[V] == INT_MAX) return {-1};
  
          vector<int> path;
          int node = V;
  
          while (parent[node] != node) {
              path.push_back(node);
              node = parent[node];
          }
          path.push_back(1);
          reverse(path.begin(), path.end());
          return path;
      }
  };