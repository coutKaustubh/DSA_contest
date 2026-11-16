class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit=0;
        for(auto x:prices){
            if(x<buy)buy = x;
            else if(x - buy > profit)profit = x-buy;
        }
        return profit;
    }
};