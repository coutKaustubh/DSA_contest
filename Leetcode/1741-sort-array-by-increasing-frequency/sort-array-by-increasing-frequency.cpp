class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x : nums)mp[x]++;
            priority_queue<pair<int, int>,vector<pair<int, int>>,function<bool(pair<int,int>, pair<int,int>)>
        > minheap(
            [](pair<int,int> a, pair<int,int> b) {
                if (a.first == b.first)
                    return a.second < b.second; 
                return a.first > b.first;
            }
        );


        for (auto p : mp) {
            minheap.push({p.second, p.first});
        }

        vector<int> ans;
        int fr;
        while (!minheap.empty()) {
        fr = minheap.top().first;
           while(fr){
                ans.push_back(minheap.top().second);
                fr--;
           }
           minheap.pop();
        }
        return ans;
    }
};