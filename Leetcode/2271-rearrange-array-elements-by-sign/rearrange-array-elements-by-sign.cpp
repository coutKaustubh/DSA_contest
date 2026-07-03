class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int idx = min(pos.size(),neg.size());
        for(int i=0;i<idx;i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }

        if(pos.size()>neg.size()){
            int index = neg.size()*2;
            for(int i=neg.size();i<pos.size();i++){
                nums[index++] = pos[i];
            }
        }
        else{
            int index = pos.size()*2;
            for(int i=pos.size();i<neg.size();i++){
                nums[index++] = neg[i];
            }
        } 
        return nums;
    }
};