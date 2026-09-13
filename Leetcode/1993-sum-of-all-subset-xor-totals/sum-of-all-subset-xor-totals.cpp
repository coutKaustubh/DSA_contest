class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n =nums.size(); int p = 1<<n;
        vector<vector<int>> subs(p);
        int ans=0,x=0;
       for(int i=0;i<p;i++){
        x=0;
        for(int j=0;j<n;j++){
            if((i>>j) & 1){
                subs[i].push_back(nums[j]);
                x ^= nums[j];
            }
        }
        ans+=x;
       }
       return ans;
    }
};