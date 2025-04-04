class Solution {
    public:
        vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(n);  
            vector<int> indegree(n, 0);  
    
            for (auto& edge : prerequisites) {
                int course = edge[1], prerequisite = edge[0];
                adj[prerequisite].push_back(course);
                indegree[course]++;
            }
    
            queue<int> qu;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    qu.push(i);
                }
            }
    
            vector<int>topo; 
            while (!qu.empty()) {
                int node = qu.front();
                qu.pop();
                topo.push_back(node);
                for (int neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        qu.push(neighbor);
                    }
                }
            }
            reverse(topo.begin(),topo.end());
            if(topo.size()==n) return topo;
            return {};  
        }
    };