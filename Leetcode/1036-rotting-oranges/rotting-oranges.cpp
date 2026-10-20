class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh =0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)fresh++;
            }
        }


        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        int time = 0;
        while(!q.empty() && fresh>0){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >=0  && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                        fresh--;
                    }
                }
            }
            time++;
        }
       return fresh ==0 ? time:-1;
    }
};