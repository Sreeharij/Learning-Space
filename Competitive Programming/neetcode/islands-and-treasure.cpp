//DFS APPROACH BELOW
class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<int>>& grid){
        if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != -1){
            return true;
        }
        return false;
    }

    void dfs(int x,int y,int rows,int cols,vector<vector<int>>& grid,int distance){
        if(grid[x][y] == 0 && distance!=0){
            return;
        }
        if(distance < grid[x][y] || grid[x][y] == 0){
            grid[x][y] = distance;
        }
        else{
            return;
        }
        if(is_valid(x+1,y,rows,cols,grid)){
            dfs(x+1,y,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x-1,y,rows,cols,grid)){
            dfs(x-1,y,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x,y+1,rows,cols,grid)){
            dfs(x,y+1,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x,y-1,rows,cols,grid)){
            dfs(x,y-1,rows,cols,grid,grid[x][y]+1);
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
            dfs(x.first,x.second,rows,cols,grid,distance);
        }
    }
};



//BFS APPROACH BELOW
class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<int>>& grid){
        if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == INT_MAX){
            return true;
        }
        return false;
    }  

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x_coord = q.front().first;
            int y_coord = q.front().second;
            q.pop();
            if(is_valid(x_coord+1,y_coord,rows,cols,grid)){
                grid[x_coord+1][y_coord] = grid[x_coord][y_coord] + 1;
                q.push({x_coord+1,y_coord});
            }
            if(is_valid(x_coord-1,y_coord,rows,cols,grid)){
                grid[x_coord-1][y_coord] = grid[x_coord][y_coord] + 1;
                q.push({x_coord-1,y_coord});
            }
            if(is_valid(x_coord,y_coord+1,rows,cols,grid)){
                grid[x_coord][y_coord+1] = grid[x_coord][y_coord] + 1;
                q.push({x_coord,y_coord+1});
            }
            if(is_valid(x_coord,y_coord-1,rows,cols,grid)){
                grid[x_coord][y_coord-1] = grid[x_coord][y_coord] + 1;
                q.push({x_coord,y_coord-1});
            }
        }
    }
};
