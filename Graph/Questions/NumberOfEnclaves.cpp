class Solution {
    public:
            void bfs(int startr,int startc,vector<vector<int>>& grid,vector<vector<int>> &visited){
                int n=grid.size();
                int m=grid[0].size();
                queue<pair<int,int>>q;
                q.push({startr,startc});
                visited[startr][startc]=1;
                int delrow[]={-1,0,+1,0};
                int delcol[]={0,+1,0,-1};
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                            int nrow=x+delrow[i];
                            int ncol=y+delcol[i];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                            visited[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            } 
        int numEnclaves(vector<vector<int>>& grid) {
                int n=grid.size();
                int m=grid[0].size();
                vector<vector<int>>visited(n,vector<int>(m,0));
                for(int i=0;i<n;i++){
                    if(!visited[i][0] && grid[i][0]==1){
                        bfs(i,0,grid,visited);
                    }
                    if(!visited[i][m-1] && grid[i][m-1]==1){
                        bfs(i,m-1,grid,visited);
                    }
                }
                for(int j=0;j<m;j++){
                    if(!visited[0][j] && grid[0][j]==1){
                        bfs(0,j,grid,visited);
                    }
                    if(!visited[n-1][j] && grid[n-1][j]==1){
                        bfs(n-1,j,grid,visited);
                    }
                }
                int count=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(visited[i][j]==0 && grid[i][j]==1){
                            count++;
                        }
                    }
                }
                return count;
        }
    };