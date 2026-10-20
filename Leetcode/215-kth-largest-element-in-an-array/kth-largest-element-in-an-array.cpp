class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minH;
        for(auto x:nums){
            minH.push(x);
            if(minH.size() > k)minH.pop();
        }
        return minH.top();
    }
};