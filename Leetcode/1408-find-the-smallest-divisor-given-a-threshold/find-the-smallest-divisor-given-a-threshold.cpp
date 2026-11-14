class Solution {
public:
    bool checkthreshold(vector<int>&nums,int threshold,int divisor){
        int c=0;
        for(int i=0;i<nums.size();i++){
            c+= (nums[i]+divisor-1)/divisor;
        }
        return c<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(checkthreshold(nums,threshold,mid))high = mid-1;
            else low=mid+1;
        }
        return low;
    }
};