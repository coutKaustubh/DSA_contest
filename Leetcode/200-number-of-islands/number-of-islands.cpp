class Solution {
public:
    void dfs(vector<vector<char>>& adj, int i, int j) {
        int n = adj.size();
        int m = adj[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m)return;
        if(adj[i][j] == '0')return;
        adj[i][j] = '0';
        dfs(adj, i - 1, j); 
        dfs(adj, i + 1, j); 
        dfs(adj, i, j - 1); 
        dfs(adj, i, j + 1); 
    }   
    int numIslands(vector<vector<char>>& adj) {
        //same as no of provinces
        /*
        Input: adj = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
is wale question me jitne 1 h sb milke ek hi province ya fir ek hi connected component h
 question is framed in a way ki it says island charfo taraf se paani se ghira hona chahiye but if we explain this sentence it means ki agar charo taraf 0 h iska mtlb h ki voh ek alag component h therefore we just need to find no of components
        */
    
    int n = adj.size();
    int m = adj[0].size();
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(adj[i][j] != '0') {
                count++;
                dfs(adj, i, j);
                }
            }
        }
    return count;
    }
};