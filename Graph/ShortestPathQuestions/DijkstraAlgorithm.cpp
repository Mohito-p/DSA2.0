//priority queue
//Time Complexity O(ElogV)
class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          int v=adj.size();
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          vector<int>dist(v,INT_MAX);
          
          dist[src]=0;
          pq.push({0,src});
          
          while(!pq.empty()){
              int dis=pq.top().first;
              int node=pq.top().second;
              pq.pop();
              
              for(auto it: adj[node]){
                  int edgeWeight=it.second;
                  int adjNode=it.first;
                  
                  if(dis+edgeWeight< dist[adjNode]){
                      dist[adjNode] = dis+edgeWeight;
                      pq.push({dist[adjNode],adjNode});
                  }
              }
          }
          return dist;
          
      }
  };

  // Using Set

  class Solution {
    public:
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          int v=adj.size();
          set<pair<int,int>>st;
          vector<int>dist(v,INT_MAX);
          
          st.insert({0,src});
          dist[src]=0;
          
          while(!st.empty()){
              auto it = *(st.begin());
              int node=it.second;
              int dis=it.first;
              st.erase(it);
              
              for(auto it: adj[node]){
                  int adjNode=it.first;
                  int edgW=it.second;
                  
                  if(dis + edgW < dist[adjNode]){
                      if(dist[adjNode]!=INT_MAX){
                          st.erase({dist[adjNode],adjNode});
                      }
                      dist[adjNode]=dis+edgW;
                      st.insert({dist[adjNode],adjNode});
                  }
              }
          }
          return dist;
      }
  };

