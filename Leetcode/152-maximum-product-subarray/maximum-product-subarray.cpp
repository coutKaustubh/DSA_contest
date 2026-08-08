class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefProd = 1,suffProd=1,mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefProd == 0)prefProd=1;
            if(suffProd==0)suffProd=1;
            prefProd *= nums[i];
            suffProd *= nums[nums.size()-i-1];

            mx = max(mx,max(prefProd,suffProd));
        }       
        return mx;
    }
};