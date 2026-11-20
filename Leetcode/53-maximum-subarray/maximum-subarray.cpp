class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        int mx = nums[0];
        int tempStart = 0;
        int start = 0, end = 0;

        for (int i = 1; i < n; i++) {

            if (nums[i] > curr + nums[i]) {
                curr = nums[i];
                tempStart = i;
            } else {
                curr += nums[i];
            }

            if (curr > mx) {
                mx = curr;
                start = tempStart;
                end = i;
            }
        }
        return mx;
    }
};