class Solution {
    public:
        int numIslandsDistinct(vector<vector<char>>& grid) {
            vector<vector<int>> vis(n, vector<int>(m, 0));
            queue<pair<int, int>> q;
            set<vector<pair<int, int>>> s;
            vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        vector<pair<int, int>> vec;
                        q.push({i, j});
                        vis[i][j] = 1;
                        vec.push_back({0, 0}); 
            
                        while (!q.empty()) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            
                            for (int k = 0; k < 4; k++) {
                                int newx = x + dir[k][0];
                                int newy = y + dir[k][1];
                                
                                if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 && !vis[newx][newy]) {
                                    q.push({newx, newy});
                                    vis[newx][newy] = 1;
                                    vec.push_back({newx - i, newy - j}); 
                                }
                            }
                        }
                        s.insert(vec);
                    }
                }
            }
            return s.size();
        }
    };