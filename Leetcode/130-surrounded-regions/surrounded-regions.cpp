class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n &&  ncol >= 0 && ncol < m
             && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) dfs(nrow, ncol, board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Boundary ke O se DFS
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' &&
                   (i == 0 || i == n-1 || j == 0 || j == m-1) && !vis[i][j]) {
                    dfs(i, j, board, vis);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};