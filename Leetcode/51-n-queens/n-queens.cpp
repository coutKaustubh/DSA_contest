class Solution {
public:
    bool isSafe(vector<int>& QueensPos, int row, int col){
        for(int prevRow = 0;prevRow<row;prevRow++){ // prevrow ka sb check kro if in same col or in same diagonal
        //same col
        int prevCol = QueensPos[prevRow];
        if(prevCol == col)return false;

        //same diagonal
        if(abs(prevRow-row) == abs(prevCol-col))return false;
        }  
        return true;
    }
    void backtrack(vector<int>&QueensPos,int row,vector<vector<string>>&ans){
        if(row == QueensPos.size()){
            int n =  QueensPos.size();
            vector<string> board(n, string(n, '.')); 
            /*
            queenpos is vector whcih stores pos of queen in ith row means ith index of queenpos represent ith row pr queen kaha placed h
            queenpos = [1 3 0 2]
            so 1st row me queen is 1st pos ... 
            so we made a 2d string
            ....
            ....
            ....
            ....
            */
            for(int r=0;r<n;r++){
                board[r][QueensPos[r]] = 'Q';
            }
            /*
            now here we did board[0][queenpos[0]] = 'q' means 0th row me jahan queen h usko q kr do
            ...
            */
            ans.push_back(board);
            return;
        }

        for(int col=0;col<QueensPos.size();col++){
            if(isSafe(QueensPos,row,col)){
                QueensPos[row] = col;
                backtrack(QueensPos,row+1,ans);
                QueensPos[row] = -1;
            }
            //if nothing is safe returns to its previous called fun i.e on line 42 and thrn 43 exectues after that which is that previous row becomes -1 and we call for it

            /*
            wait imagine
            n=4

            now 1st pos is safe in row 1
            so queenspos = [0,-1,-1,-1] 
            now loop runs more
            col = 1 , 
            row = 1 not safe
            col = 2 row =1 safe
            
            so
            queen pos = [0,2,-1,-1] now 
            col = 3 row = 2
            not safe
            col 4 row = 2 not safe

            now returns to prev
            call = 2 row = 1
            popback or queenpos[row ]= -1
            there queenpos [ 0 -1 -1 -1]

            now call 3 row = 1

            so if you are confused on a point ki if we pop back to prev and jb is isSafe check rkega toh vapas same col pr true return kr dega but nhi since loop chalegi once again so col uske aage se check hoga wo wala kbhi check hi nhi hoga
            */
        }

        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int>QueensPos(n,-1);
        vector<vector<string>>ans;
        backtrack(QueensPos,0,ans);
        return ans;
    }
};