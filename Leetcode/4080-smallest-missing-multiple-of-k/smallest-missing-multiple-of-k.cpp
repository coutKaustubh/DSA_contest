class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;

        int c = k;

        for(int i = 0; i <= nums.size(); i++) {
            mp[c] = false;
            c += k;
        }

        for(auto x : nums) {
            if(x % k == 0) {
                mp[x] = true;
            }
        }

        int ans = INT_MAX;

        for(auto x : mp) {
            if(x.second == false && x.first < ans) {
                ans = x.first;
            }
        }

        return ans;
    }
};