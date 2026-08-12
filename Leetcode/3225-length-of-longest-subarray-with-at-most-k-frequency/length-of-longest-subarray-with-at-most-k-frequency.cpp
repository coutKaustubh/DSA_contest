class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int l = 0, mx = 0;

        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};