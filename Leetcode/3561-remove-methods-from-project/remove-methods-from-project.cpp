class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& invoke, vector<int>& vis) {
        vis[node] = 1;
        for (auto &it : invoke[node]) {
            if (!vis[it]) {
                dfs(it, invoke, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>mp;
       
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
        }

        vector<int> vis(n, 0);
        dfs(k, mp, vis);

        vector<int> rem;

        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                rem.push_back(i);
        }

        return rem;

    }
};
