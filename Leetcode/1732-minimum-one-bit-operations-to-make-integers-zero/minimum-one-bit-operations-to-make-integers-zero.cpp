class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)return 0;
        vector<int>precomputeIfonebitset(32,0); //32 bits
        precomputeIfonebitset[0] = 1;
        int i=1;
        while(i<32) {
            precomputeIfonebitset[i] = 2LL*precomputeIfonebitset[i-1]+1;
            i++;
        }
        int ans=0;int sign=1; //1 = +ve -1 = -ve
        for(int i=31;i>=0;i--){
            int ithBit = (n&(1LL<<i));
            if(ithBit){
                if(sign>0)ans += (precomputeIfonebitset[i]);
                else ans -= precomputeIfonebitset[i];
                sign = sign*(-1); 
            }
        }
        return ans;
    }
};   