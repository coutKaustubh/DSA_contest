class Solution {
public:
    bool dfs(int node, int target,unordered_map<int, vector<int>>& adjls,vector<int>& vis) {
        if (node == target) return true;
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                if (dfs(it, target, adjls, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adjls;
        for(int i=0;i<n;i++){
            vector<int>vis(n+1,0);
            int u = edges[i][0];
            int v = edges[i][1];
            /*
            ques ye keh rha ki hme last edge do jisko add krne se cycle bn rhi
            toh apan graph bnana start krenge edges ke sequence me jo question me diya h and jiase hi cycle bni we will return it
            */

            //yahan check kr rhe bs ki u aur v connected h ki nahi
            if (dfs(u, v, adjls, vis)) {
                return edges[i];
            }

            //agar nahi conncted h toh add edge
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        
        return {};
    }
};