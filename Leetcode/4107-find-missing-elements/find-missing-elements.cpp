class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
     sort(nums.begin(),nums.end());
    vector<int>ans;
        int mn=nums[0];
        int mx = nums[nums.size()-1];
        int j=1;
        for(int i=mn+1;i<mx;i++){
            if(nums[j]!=i){
                ans.push_back(i);
            }
            else
            j++;
        }
        return ans;
    }
};