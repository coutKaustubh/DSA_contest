class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m)return 0;
        if(vis[i][j] || grid[i][j] == 0)return 0;
        vis[i][j] = 1;
        int count = 1; //bcz 1 visited
        count += dfs(grid,vis,i-1,j);
        count += dfs(grid,vis,i,j-1);
        count += dfs(grid,vis,i,j+1);
        count += dfs(grid,vis,i+1,j);

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)ans = max(ans,dfs(grid,vis,i,j));
            }
        }
        return ans;
    }
};