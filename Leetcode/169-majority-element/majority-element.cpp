class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]++;
        int ele = -1,mx=-1;
        for(auto x:mp){
            if(x.second > mx){
                mx = x.second;
                ele = x.first;
            }
        }
        return ele;

    }
};