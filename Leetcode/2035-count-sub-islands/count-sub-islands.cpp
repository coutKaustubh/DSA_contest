class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int, int>>& temp) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        temp.push_back({i, j});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind++) {
            int nrow = i + delrow[ind];
            int ncol = j + delcol[ind];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis, temp);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1,vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>> grid1vp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid1, vis, temp);
                    grid1vp.push_back(temp);
                }
            }
        }
        fill(vis.begin(), vis.end(), vector<int>(m, 0));
        vector<vector<pair<int, int>>> grid2vp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid2, vis, temp);
                    grid2vp.push_back(temp);
                }
            }
        }

        int count = 0;

        for (auto& island : grid2vp) {
            bool valid = true;

            for (auto& cell : island) {
                int x = cell.first;
                int y = cell.second;

                if (grid1[x][y] == 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) count++;
        }

        return count;
    }
};
