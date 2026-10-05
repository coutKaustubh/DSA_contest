class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int,int>>> maxheap;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;

            maxheap.push({distance, {x, y}});

            if(maxheap.size() > k)
                maxheap.pop();
        }

        vector<vector<int>> ans;
        while(!maxheap.empty()) {

            ans.push_back({
                maxheap.top().second.first,
                maxheap.top().second.second
            });

            maxheap.pop();
        }

        return ans;
    }
};