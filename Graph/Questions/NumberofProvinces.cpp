class Solution {
    public:
        vector<int> visited;
        int v;
    
        void bfs(int start, vector<vector<int>>& graph) {
            queue<int> q;
            visited[start] = 1;
            q.push(start);
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbour = 0; neighbour < v; neighbour++) {
                    if (graph[curr][neighbour] == 1 && !visited[neighbour]) { 
                        q.push(neighbour);
                        visited[neighbour] = 1;
                    }
                }
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            v = n;
            visited.assign(v, 0);
            int count = 0;
    
            for (int i = 0; i < v; i++) {
                if (visited[i] == 0) {
                    count++;
                    bfs(i, isConnected);
                }
            }
            return count;
        }
    };
    