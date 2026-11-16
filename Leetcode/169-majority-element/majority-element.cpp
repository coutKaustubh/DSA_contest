class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,ele=0;
        int n = nums.size();
        for(auto x:nums){
            if(c==0)ele = x;
            if(ele == x)c++;
            else c--;
        }
        c=0;
        for(auto x:nums){
            if(x==ele)c++;
        }

        return c>n/2?ele:-1;
    }
};