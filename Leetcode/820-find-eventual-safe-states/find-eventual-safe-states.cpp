class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>>&adjls,vector<int>&vis,vector<int>&Pathvis,vector<int>&check){
        vis[node] = 1;
        Pathvis[node] = 1;


        for(auto it:adjls[node]){
            if(!vis[it]){
                if(dfs(it,adjls,vis,Pathvis,check)){
                    check[it] = 0;
                    return true;
                }
            }
            else{
                if(Pathvis[it]){
                    check[it] = 0;
                    return true;
                }
            }
        }    
        Pathvis[node] = 0;
        check[node] = 1;

        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adjls;
        int n = graph.size();
        for(int i=0;i<n;i++){
            int m = graph[i].size();
            for(int j=0;j<m;j++){
                adjls[i].push_back(graph[i][j]);
            }
        }
        vector<int>vis(n,0);
        vector<int>Pathvis(n,0);
        vector<int>check(n,0);
        vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adjls,vis,Pathvis,check);
            }
        }

        for(int i=0;i<n;i++){
            if(check[i])safenodes.push_back(i);
        }
    return safenodes;
    }



};