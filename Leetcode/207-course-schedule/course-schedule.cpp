
class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& Pathvis,unordered_map<int, vector<int>>& adjls) {
        vis[node] = 1;
        Pathvis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, Pathvis, adjls))
                    return true;
            }
            else if (Pathvis[it]) {
                return true;
            }
        }

        Pathvis[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjls;
        for (auto &p : prerequisites) {
            adjls[p[1]].push_back(p[0]);
        }
        vector<int> vis(n, 0);
        vector<int> Pathvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, Pathvis, adjls))
                    return false;
            }
        }
        return true;
    }
};
