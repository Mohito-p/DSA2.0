//bfs
class Solution {
    public:
    
        bool isBipartite(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<int>color(n,-1);
            queue<int>q;
            for(int i=0;i<n;i++){
            if(color[i]==-1){
            color[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto neighbour : graph[node]){
                    if(color[neighbour]==-1){
                       if(color[node]==0){
                         color[neighbour]=1;
                       }
                       else if(color[node]==1){
                        color[neighbour]=0;
                       }
                       q.push(neighbour);
                    }
                    else{
                        int y=color[neighbour];
                        for(auto it : graph[neighbour]){
                           if(y==color[it]){
                            return false;
                           }
                           else{
                             continue;
                           }
                        }
                    }
                  }
                }
              } 
            }
            return true;
        }
    };

//dfs

class Solution {
    public:
        bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int currentColor) {
            color[node] = currentColor;
            for (auto neighbour : graph[node]) {
                if (color[neighbour] == -1) {
                    if (!dfs(neighbour, graph, color, 1 - currentColor)) {
                        return false;
                    }
                } else if (color[neighbour] == color[node]) {
                    return false;
                }
            }
            return true;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, -1);
            
            for (int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    if (!dfs(i, graph, color, 0)) {
                        return false;
                    }
                }
            }
            return true;
        }
    };