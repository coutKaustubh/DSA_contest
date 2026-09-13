class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int I1,I2;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1] > nums[i]){
                I1 = i;
                I2 = i+1;
                flag = false;
                break;
            }
        }
        if(flag)return reverse(nums.begin(),nums.end());
        for(int i=n-1;i>=I2;i--){
            if(nums[i] > nums[I1]){
                swap(nums[i],nums[I1]);
                break;
            }
        }
        reverse(nums.begin()+I2,nums.end());
    }
};