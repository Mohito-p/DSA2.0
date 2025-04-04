class Solution {
    public:
        void bfs(int startr,int startc,vector<vector<char>>& board,vector<vector<int>> &visited){
            int n=board.size();
            int m=board[0].size();
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
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        } 
        void solve(vector<vector<char>>& board) {
            int n=board.size();
            int m=board[0].size();
            vector<vector<int>>visited(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                if(!visited[i][0] && board[i][0]=='O'){
                    bfs(i,0,board,visited);
                }
                if(!visited[i][m-1] && board[i][m-1]=='O'){
                    bfs(i,m-1,board,visited);
                }
            }
            for(int j=0;j<m;j++){
                if(!visited[0][j] && board[0][j]=='O'){
                    bfs(0,j,board,visited);
                }
                if(!visited[n-1][j] && board[n-1][j]=='O'){
                    bfs(n-1,j,board,visited);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(visited[i][j]==0){
                        board[i][j]='X';
                    }
                }
            }
        }
    };