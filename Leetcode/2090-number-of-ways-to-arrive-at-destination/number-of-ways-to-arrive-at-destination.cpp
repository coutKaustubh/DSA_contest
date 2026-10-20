class Solution {
public:
    typedef pair<long long, int> ppi;
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> adjls;
        for (auto &it : roads) {
            adjls[it[0]].push_back({it[1], it[2]});
            adjls[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1; 
        // ways represernt ki node tk pahuchne ke kitne raste h 
        pq.push({0, 0});
        while (!pq.empty()) {
            long long time1 = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (time1 > dist[node]) continue;
            for (auto it : adjls[node]) {
                int newnode = it.first;
                long long timetaken = it.second;
                long long newTime = time1 + timetaken;
                if (newTime < dist[newnode]) {
                    dist[newnode] = newTime;
                    ways[newnode] = ways[node];
                    pq.push({newTime, newnode});
                }

                else if (newTime == dist[newnode]) {
                    ways[newnode] = (ways[newnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};