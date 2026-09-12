class Solution {
public:
    const long long MOD = 1e9 + 7;

    int maximumXorProduct(long long a, long long b, int n) {
        long long x=0;
        for (int i = n-1; i>=0; i--) {
            long long bit = 1LL<<i; // us wale bit ko 1 kiya
            bool abit = a & bit;  // a ke sath AND liya bcz a me us bit pr kya h pta chale
            bool bbit = b & bit; // same for b
            if (!abit && !bbit)x |= bit; //agar dono 0 h toh xor wale me opposite sign put kr do to maximize, i.e 1 kr diye us bit pr put
            
            else if(abit && bbit){} //-  is case me already 0 h hi
            //now case if a ka bit 0 and b ka 1 , ya fir b ka 0 and a ka 1
            else{
                long long A = a^x;       
                long long B = b^x;

                //pattern se notice hoga ki 
                // do num ka miultiplication me agar chote wale ko increase kre and bade ko same toh value jyada badi hoti in comparision agar bade wale ko increase kre
                //so hamari preference h ki chote wale bit ke opposite bit rkhe in x ki chota wale ka bit 1 ho jaye and total value badh jaye

                if(A<B){
                    if(!abit)x|=bit; //same cheej, us wale bit ko 1 kr do agar abhi chote wale num (yaani a) pr 0 h
                    else{} // idhar us bit pr 0 kr do bcz aka bit yaani abit is 1, already x ke us bit pr 0 h hi
                } 
                else{
                    if(!bbit)x|=bit;  //same
                    else{} // same - already x ke us bit pr 0 h hi
                }
            }
        }
    
        return ((a ^ x) % MOD * ((b ^ x) % MOD)) % MOD; //final
    }

};