class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele =-1;
        int cnt = 0;
        // intuition - cnt ++ when we find similar ele else cnt -- , so if at end cnt>0 so that ele is majority

        for(int i=0;i<nums.size();i++){
            if(cnt==0)ele = nums[i];
            if(ele == nums[i])cnt++;
            else cnt--;
        }

        return ele;
    }
};