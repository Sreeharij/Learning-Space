class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != -1){
            return true;
        }
        return false;
    }

    void dfs(int x,int y,int rows,int cols,vector<vector<bool>>& visited,vector<vector<int>>& grid,int distance){
        visited[x][y] = true;
        if(grid[x][y] == 0 && distance!=0){
            return;
        }
        if(distance < grid[x][y] || grid[x][y] == 0){
            grid[x][y] = distance;
        }
        else{
            return;
        }
        if(is_valid(x+1,y,rows,cols,grid,visited)){
            dfs(x+1,y,rows,cols,visited,grid,grid[x][y]+1);
        }
        if(is_valid(x-1,y,rows,cols,grid,visited)){
            dfs(x-1,y,rows,cols,visited,grid,grid[x][y]+1);
        }
        if(is_valid(x,y+1,rows,cols,grid,visited)){
            dfs(x,y+1,rows,cols,visited,grid,grid[x][y]+1);
        }
        if(is_valid(x,y-1,rows,cols,grid,visited)){
            dfs(x,y-1,rows,cols,visited,grid,grid[x][y]+1);
        }
    }      

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int,int>> tressure;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    tressure.push_back({i,j});
                }
            }
        }
        for(auto x: tressure){
            int distance = 0;
            vector<vector<bool>> visited(rows,vector<bool>(cols,false));
            dfs(x.first,x.second,rows,cols,visited,grid,distance);
        }
    }
};
