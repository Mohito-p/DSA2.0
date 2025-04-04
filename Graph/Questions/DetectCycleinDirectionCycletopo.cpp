class Solution {
    public:
      bool Check(vector<vector<int>> &graph,int v){
      vector<int> indegree(v,0);
      for(int i=0;i<v;i++){
          for(auto neighbour:graph[i]){
              indegree[neighbour]++;
          }
      }
      queue<int>qu;
      unordered_set<int>vis;
      for(int i=0;i<v;i++){
          if(indegree[i]==0){
              qu.push(i);
              vis.insert(i);
          }
      }
      int cnt=0;
      while(!qu.empty()){
          int node=qu.front();
          qu.pop();
          cnt++;
          for(auto neighbour: graph[node]){
              if(!vis.count(neighbour)){
                  indegree[neighbour]--;
                  if(indegree[neighbour]==0){
                      qu.push(neighbour);
                      vis.insert(neighbour);
                  }
              }
          }
      }
      if(cnt==v) return false;
      return true;
  }
      bool isCyclic(vector<vector<int>> &adj) {
          int v=adj.size();
          return  Check(adj,v);
      }
  };