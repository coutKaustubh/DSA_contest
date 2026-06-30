class Solution {
public:
    void sortColors(vector<int>& nums) {
        multiset<int>st;
        for(auto x:nums)st.insert(x);
        nums.clear();
        for(auto x:st)nums.push_back(x);
        
    }
};