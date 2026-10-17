class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        vis[i][j]  = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        for(int ind = 0;ind<4;ind++){
            int nrow = i + delrow[ind];
            int ncol = j + delcol[ind];

            if(nrow>=0 && ncol >= 0 && nrow<n && ncol<m){
                if(!vis[nrow][ncol] && board[nrow][ncol] == 'X')dfs(nrow,ncol,vis,board);
            }
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    dfs(i,j,vis,board);
                    c++;
                }
            }
        }
        return c;
    }
};