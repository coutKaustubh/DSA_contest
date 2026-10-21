
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        //ulta bharna start krenge toh aise hi hoga

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--) { // i=n-2 se start bcz last row already initialized h
            for (int j = 0; j < n; j++) {
                int down = dp[i + 1][j];
                int left = (j > 0)? dp[i + 1][j - 1] : INT_MAX;
                int right = (j + 1 < n)? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({down, left, right});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};
