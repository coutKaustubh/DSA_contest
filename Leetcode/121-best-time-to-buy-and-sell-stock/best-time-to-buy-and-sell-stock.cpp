class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        vector<int>consecSell(n-1);
        for(int i =0;i<n-1;i++){
            consecSell[i] = prices[i+1]-prices[i];
        }
        n=n-1;
        int curr = consecSell[0];
        int mx = curr;
        for(int i=1;i<n;i++){
            curr = max(consecSell[i] , curr+consecSell[i]);
            mx = max(mx,curr);
        }

        return mx<0?0:mx;
    }
};