class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>st;
        for(auto it: nums)st.insert(it);
        int c=1,mx=0;
        for(auto it:st){
            if(st.find(it-1) == st.end()){
                c=1;
                int k = it+1;
                while(st.find(k) != st.end()){
                    k++;
                    c++;
                }
                mx = max(c,mx);
            }
        }
        return mx;
    }
};