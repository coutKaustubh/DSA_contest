class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        if (nums.size() == 1) {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.insert(singleList);
            vector<vector<int>>ans(res.begin(),res.end());
            return ans;  
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> remainingNums;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }
            
            vector<vector<int>> perms = permuteUnique(remainingNums);
            for (vector<int> p : perms) {
                p.insert(p.begin(), n);  
                res.insert(p);  
            }
        }
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;    
    }
};