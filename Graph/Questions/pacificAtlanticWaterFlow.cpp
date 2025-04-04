class Solution {
public:
    
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
    vector<vector<int>>h;
    vector<vector<bool>> bfs(queue<pair<int,int>> &qu){
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        while(!qu.empty()){
            auto cell=qu.front();
            qu.pop();
            int i=cell.first;
            int j=cell.second;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int newRow=i+dir[d][0];
                int newCol=j+dir[d][1];
                if(newRow<0 || newCol<0 || newRow>=rows || newCol>=cols) continue;
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol]<h[i][j]) continue;
                qu.push({newRow,newCol});
            }
        }
        return visited;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         rows=heights.size();
         cols=heights[0].size();
         h=heights;
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;
        //steps for multisource bfs
        for(int i=0;i<rows;i++){
            pacific.push({i,0});
            atlantic.push({i,cols-1});
        }
        for(int j=1;j<cols;j++){
            pacific.push({0,j});
        }
        for(int j=0;j<cols-1;j++){
            atlantic.push({rows-1,j});
        }
        vector<vector<bool>> pacificv=bfs(pacific);
        vector<vector<bool>> atlanticv=bfs(atlantic);
        
        vector<vector<int>> result;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacificv[i][j] && atlanticv[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};