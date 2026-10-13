class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        for (int i = 0; i < n-1; i++) {
            for (auto it : times) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};