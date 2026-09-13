class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int mx2=0;
        bool flag=false;
        for(auto x:nums){
            if(x==mx && !flag){
                flag=true;
                continue;
            }
            if(x>mx2)mx2=x;
        }
        return (mx-1) * (mx2-1);
    }
};