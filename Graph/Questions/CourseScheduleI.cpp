class Solution {
    public:
        bool canFinish(int n, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(n);  
            vector<int> indegree(n, 0);  
    
            for (auto& edge : prerequisites) {
                int course = edge[0], prerequisite = edge[1];
                adj[prerequisite].push_back(course);
                indegree[course]++;
            }
    
            queue<int> qu;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    qu.push(i);
                }
            }
    
            int count = 0;  
            while (!qu.empty()) {
                int node = qu.front();
                qu.pop();
                count++;
    
                for (int neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        qu.push(neighbor);
                    }
                }
            }
    
            return count == n;  
        }
    };