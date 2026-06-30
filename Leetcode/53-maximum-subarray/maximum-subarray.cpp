class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        int mx = nums[0];
        for(int i=1;i<n;i++){
            curr = max(nums[i] ,nums[i] + curr);
            mx = max(mx,curr);
        }

        return mx;
    }
};