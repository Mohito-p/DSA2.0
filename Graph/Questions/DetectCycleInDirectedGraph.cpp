class Solution{
    private:
     bool dfs(int node,vector<vector<int>>adj,vector<int>vis,vector<int>pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,adj,vis,pathVis)) return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
     }
     public:
     bool containsCycle(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                if(dfs(i,adj,vis,pathVis)) return true;
        }
        return false;
     }
};