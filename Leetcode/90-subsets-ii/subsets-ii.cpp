class Solution {
public:
void generate(set<vector<int>>& ans, vector<int>& temp,
                  vector<int>& nums, int index) {

        if (index == nums.size()) {
            ans.insert(temp);
            return;
        }
        generate(ans, temp, nums, index + 1);
        temp.push_back(nums[index]);
        generate(ans, temp, nums, index + 1);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        generate(st,temp,nums,0);

        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};