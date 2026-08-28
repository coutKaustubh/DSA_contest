class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int i,int j,int index){
        if(index == word.size())return true;
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size())return false;
        if(board[i][j] != word[index])return false;
        //marking visites bcz same iteration me ek index 2 bar choose na ho isliye
        char temp = board[i][j];
        board[i][j] = '$';

        bool ans = backtrack(board,word,i+1,j,index+1)||
                    backtrack(board,word,i-1,j,index+1)||
                    backtrack(board,word,i,j+1,index+1)||
                    backtrack(board,word,i,j-1,index+1);

        // backtracking and putting same char there again which we marked as #;
        board[i][j] = temp;

        return ans;
                
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(backtrack(board,word,i,j,0))return true;
                }
            }
        }
        return false;
    }
};