class Solution {
public:
    bool possible(vector<int>&arr,int wt, int days){
        int sum=0;
        int c=1;
        for(auto x:arr){
            if(sum + x <= wt){
                sum += x;
            }
            else{
                c++;
                sum=x;
            }
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(weights,mid,days))high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};