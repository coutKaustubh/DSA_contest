class Solution {
public:
    long long MOD = 1000000007;
    long  power(long  x,long  n){
        if(n==0)return 1;
        long temp = power(x,n/2) ;

        if(n&1){
            return (x*temp*temp)%MOD;
        }
        else return (temp*temp)%MOD;
    }
    int countGoodNumbers(long long n) {
        long  even = (n+1)/2;
        long  odd = n/2;
        long  first = power(5,even)%MOD;
        long  second = power(4,odd)%MOD;
        return (int)((first*second)%MOD);
    }
};