class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Since candidates is sorted, nothing after this can work
            if (candidates[i] > target)
                break;

            //remove duplicate
            if(i>start && candidates[i] == candidates[i-1])continue;
            temp.push_back(candidates[i]);

            // i, not i+1, because we can reuse the same element
            solve(candidates, target - candidates[i], i+1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};