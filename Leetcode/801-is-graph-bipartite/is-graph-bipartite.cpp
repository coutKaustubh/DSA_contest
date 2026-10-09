class Solution {
public:
    bool bfs(int node,unordered_map<int,vector<int>>&adjls,vector<int>&color){
        queue<int>q;
        q.push(node); //node ---> parent
        color[node] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adjls[node]){
                 if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                 }
                 else if(color[it]== color[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adjls;
        int n= graph.size();
        for(int i=0;i<n;i++){
            int m = graph[i].size();
            for(int j=0;j<m;j++){
                adjls[i].push_back(graph[i][j]);
            }
        }
        vector<int>color(n,-1); //-1 no color , 0/1  both colors
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bfs(i,adjls,color))return false;
            }
        }
        return true;
    }
};