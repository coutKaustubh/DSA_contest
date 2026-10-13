class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        dist[0][0] = grid[0][0]; //starting cell ki elivation
        pq.push({grid[0][0],{0,0}});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!pq.empty()){
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1)return t;
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>= 0 && nrow<n && ncol<n){
                    int newtime = max(t,grid[nrow][ncol]);
                    //
                    if(newtime < dist[nrow][ncol]){
                        dist[nrow][ncol] = newtime;
                        pq.push({newtime,{nrow,ncol}});
                    }
                }
            }

        }
        return -1;
    }
};