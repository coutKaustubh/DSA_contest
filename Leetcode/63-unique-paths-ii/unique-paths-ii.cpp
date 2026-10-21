class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,int row, int col, int m, int n,vector<vector<int>>&dp) {
        if(obstacleGrid[row][col] == 1)return 0;
        if (row == m-1 && col == n-1) {
            return 1;
        }
        if(dp[row][col] != -1)return dp[row][col];
         int right = 0, down = 0;
        if (col + 1 < n)
            right = dfs(obstacleGrid,row, col+1, m, n, dp);
        if (row + 1 < m)
            down = dfs(obstacleGrid,row+1, col, m, n, dp);

        return dp[row][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dfs(obstacleGrid,0, 0,m, n,dp);
    }
};

