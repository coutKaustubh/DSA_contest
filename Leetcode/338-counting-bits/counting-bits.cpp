class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int x=i,cnt=0;
            while(x){
                x = x&(x-1);
                cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};