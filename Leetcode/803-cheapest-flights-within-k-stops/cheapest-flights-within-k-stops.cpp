class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjls;
        for (auto &it : flights) {
            adjls[it[0]].push_back({it[1], it[2]});
        }
        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        //yahan pr bhi queue chal jayega bcz isme bhi stops har bar + 1 hi ho rha jo ki same h har bar like leetcode 1091 so simply queue 
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if (stops > k) continue;
            for (auto it : adjls[node]) {
                int nextnode = it.first;
                int price = it.second;
                if (cost + price < dist[nextnode]) {
                    dist[nextnode] = cost + price;
                    q.push({stops+1, {nextnode, cost+price}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};