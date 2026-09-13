class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; //sum-freq;
        mp[0]=1;
        int c=0,prefSum=0;
        for(int x:nums){
            prefSum+=x;
            if(mp.find(prefSum-k) != mp.end())c+=mp[prefSum-k];
            mp[prefSum]++;
        }
        return c;
    }
};