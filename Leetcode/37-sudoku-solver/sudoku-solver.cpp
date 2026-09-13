class Solution {
public:
    bool isSafe(vector<vector<char>>& board , int row,int col,char ch){
        for(int i=0;i<9;i++){   
            if(board[i][col] == ch)return false;
            if(board[row][i] == ch)return false;
        }

        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }
    
    bool backtrack(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch = '1' ; ch<= '9' ;ch++){
                        if(isSafe(board,i,j,ch)){
                            board[i][j] = ch;

                            if(backtrack(board))return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};