class Solution {
public:
    void dfs(vector<vector<int>> &image,int currRow,int currCol,int initialColor,int newColor){
        
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>=m){
           return; 
        }
        
        if(image[currRow][currCol]!=initialColor) return;
        
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,initialColor,newColor);//down
        dfs(image,currRow,currCol-1,initialColor,newColor);//left
        dfs(image,currRow-1,currCol,initialColor,newColor);//up
        dfs(image,currRow,currCol+1,initialColor,newColor);//right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};