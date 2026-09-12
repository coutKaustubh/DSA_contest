class Solution {
public:
    const long long MOD = 1e9 + 7;

    int maximumXorProduct(long long a, long long b, int n) {
        long long x=0;
        for (int i = n-1; i>=0; i--) {
            long long bit = 1LL<<i;
            bool abit = a & bit;
            bool bbit = b & bit;
            if (!abit && !bbit)x |= bit;
            
            else if(abit && bbit){} //-  is case me already 0 h hi
            //now case if a ka bit 0 and b ka 1 , ya fir b ka 0 and a ka 1
            else{
                long long A = a^x;       
                long long B = b^x;
                if(A<B){
                    if(!abit)x|=bit;
                    else{} // already x ke us bit pr 0 h hi
                } 
                else{
                    if(!bbit)x|=bit; 
                    else{} //already x ke us bit pr 0 h hi
                }
            }
        }
    
        return ((a ^ x) % MOD * ((b ^ x) % MOD)) % MOD;
    }

};