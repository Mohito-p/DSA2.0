class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        
        int cc=0;
        for(int r=0;r<rows;r++){
           for(int c=0;c<cols;c++){
               if(grid[r][c]=='0'){
                   continue;
               }
               cc++;
               grid[r][c]='0';
               queue<pair<int,int>> qu;
               qu.push({r,c});
               while(!qu.empty()){
                   auto curr=qu.front();
                   qu.pop();
                   //go to all unvisited neighbours of the curr node
                   int currRow=curr.first;
                   int currCol=curr.second;
                   //check up
                   if(currRow-1>=0 && grid[currRow-1][currCol]=='1'){
                       qu.push({currRow-1,currCol});
                       grid[currRow-1][currCol]='0';
                   }
                   //check down
                   if(currRow+1<rows && grid[currRow+1][currCol]=='1'){
                       qu.push({currRow+1,currCol});
                       grid[currRow+1][currCol]='0';
                   }
                   //check left
                   if(currCol-1>=0 && grid[currRow][currCol-1]=='1'){
                       qu.push({currRow,currCol-1});
                       grid[currRow][currCol-1]='0';
                   }
                   //check right
                   if(currCol+1<cols && grid[currRow][currCol+1]=='1'){
                       qu.push({currRow,currCol+1});
                       grid[currRow][currCol+1]='0';
                   }
               }
           }
        }
        return cc;
    }
};
//Another code 

class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            queue<pair<int,int>>q;
            int count=0;
            vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1' && !vis[i][j]){
                        count++;
                        q.push({i,j});
                        vis[i][j]=1;
                        while(!q.empty()){
                            int x=q.front().first;
                            int y=q.front().second;
                            q.pop();
                            for(int i=0;i<4;i++){
                               int newx=x+dir[i][0];
                               int newy=y+dir[i][1];
                               if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1' && !vis[newx][newy]){
                                q.push({newx,newy});
                                vis[newx][newy]=1;
                               }
                            }
                        }
                    }
                }
            }
            return count;
        }
    };