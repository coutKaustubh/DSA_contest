class Solution {
public:
    typedef pair<int,pair<int,int>> ppi;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        if (n == 1) return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = 1; // path len = no of cell visited and initially the source cell is visted
        // priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        //no need bcz sb unit distance pr h ek step me 8 direction chala sbki distamce 1 h so har node ke liye fir chakega hi so minimal element top ke liye jo priority queue use hota h no use of it now so use simple queue which omits addtional O(logn) on push pop

        queue<ppi>q;
        q.push({1,{0,0}});
        int delrow[] = {-1,-1,-1,0,0,1,1,1};
        int delcol[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                if(nrow >=0 && nrow<n && ncol>=0 && ncol < n && grid[nrow][ncol] == 0 && dis+1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1; 
                    if(nrow == n-1 && ncol == n-1){
                        return dis+1 ;
                    }
                    q.push({dis+1 , {nrow,ncol}});
                }
                }
            }
        
        return -1;
    }
};