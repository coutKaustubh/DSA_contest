class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ct = count(nums.begin(),nums.end(),0);
        if(ct==n)return 0;
        int xr = 0;
        for(auto x:nums) xr^=x;
        return xr==0?n-1:n;
    }
};