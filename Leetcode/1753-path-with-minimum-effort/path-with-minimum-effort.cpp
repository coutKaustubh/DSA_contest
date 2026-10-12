class Solution {
public:
    typedef pair<int, pair<int, int>> ppi;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({0, {0, 0}});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while (!pq.empty()) {
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return dis;

            if (dis > dist[row][col])
                continue;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int newdis = abs(heights[nrow][ncol] - heights[row][col]);
                    int neweffort = max(dis, newdis);

                    if (neweffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};