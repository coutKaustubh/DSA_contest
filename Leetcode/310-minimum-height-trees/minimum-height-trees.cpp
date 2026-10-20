class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        // intuition - leaf node ko chhod ke jitne bhi nodes ho skte h voh sb
        // possible roots h usme se min heights wale chahiye toh leaf node h ya
        // nhi h voh degree ya outdegree se pta chalega so toposort ka idea h

        // NOTE : maximum only 2 nodes ka be root of MIN HEGIHT TREES
        unordered_map<int, vector<int>> adjls;
        vector<int> degree(n,0);
        for (int i = 0; i < n - 1; i++) {
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remaining = n;
        while (remaining > 2) {
            int size = q.size();
            remaining -= size;
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (auto it : adjls[node]) {
                    degree[it]--;
                    if (degree[it] == 1)
                        q.push(it);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};