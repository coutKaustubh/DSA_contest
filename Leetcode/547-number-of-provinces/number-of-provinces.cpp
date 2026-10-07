class Solution {
public:
    void dfs(int node , unordered_map<int,bool>&vis, unordered_map<int,vector<int>>&adjLs){
        vis[node] = true;
        for(auto it : adjLs[node]){
            if(!vis[it])dfs(it,vis,adjLs);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        //convert adj matrix to adj lists

        unordered_map<int,vector<int>>adjLs;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j] == 1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        unordered_map<int,bool>vis;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                count++;
                dfs(i,vis,adjLs);
            }
        }
        return count;
    }
};