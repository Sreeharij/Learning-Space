class Solution {
public:
    bool is_valid(vector<vector<char>>& board,int x,int y,char val){
        for(int i=0;i<9;i++){
            if(board[x][i] == val){
                return false;
            }
            if(board[i][y] == val){
                return false;
            }
        }
        int box_x_start = x/3 * 3;
        int box_y_start = y/3 * 3;
        for(int i=box_x_start;i<box_x_start+3;i++){
            for(int j=box_y_start;j<box_y_start+3;j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board,vector<pair<int,int>>& initial_empty_cells,int idx){
        if(idx == initial_empty_cells.size()){
            return true;
        }
        int x = initial_empty_cells[idx].first;
        int y = initial_empty_cells[idx].second;
        for(char val='1';val<='9';val++){
            if(is_valid(board,x,y,val)){
                board[x][y] = val;
                if(backtrack(board,initial_empty_cells,idx+1)){
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        vector<pair<int,int>> initial_empty_cells;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    initial_empty_cells.push_back({i,j});
                }
            }
        }
        backtrack(board,initial_empty_cells,0);
    }
};