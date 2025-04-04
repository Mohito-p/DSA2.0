class Solution {
    private:
 bool dfs(int node,vector<vector<int>>adj,vector<int>vis,vector<int>pathVis,vector<int>&check){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;
    for(auto child:adj[node]){
        if(!vis[child]){
            if(dfs(child,adj,vis,pathVis,check)) {
                check[node]=0;
                return true;
            }
        }
        else if(pathVis[child]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
 }
public:
vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    vector<int>check(n,0);
    vector<int>safenodes;
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i,adj,vis,pathVis,check);
    }
    for(int i=0;i<n;i++){
        if(check[i]==1) safenodes.push_back(i);
    }
    return safenodes;
}
};

//Another Method

class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> indegree(n);
            vector<vector<int>> adj(n);
            
            // Build the reverse adjacency list and calculate in-degrees.
            for (int i = 0; i < n; i++) {
                for (auto node : graph[i]) {
                    adj[node].push_back(i);
                    indegree[i]++;
                }
            }
    
            queue<int> q;
            // Push all the nodes with indegree zero in the queue.
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            vector<bool> safe(n);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                safe[node] = true;
    
                for (auto& neighbor : adj[node]) {
                    // Delete the edge "node -> neighbor".
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
    
            vector<int> safeNodes;
            for (int i = 0; i < n; i++) {
                if (safe[i]) {
                    safeNodes.push_back(i);
                }
            }
            return safeNodes;
        }
    };