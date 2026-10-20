class Solution {
public:
    int arrangeCoins(int n) {
        long l=0,r=n;
        long mid;
        while(l<=r){
            mid = l + (r-l)/2;
            long coins  =mid*(mid+1)/2;
            if(coins > n)r = mid-1;
            else if(coins < n)l=mid+1;
            else return mid;
        }

        return r;
    }
};