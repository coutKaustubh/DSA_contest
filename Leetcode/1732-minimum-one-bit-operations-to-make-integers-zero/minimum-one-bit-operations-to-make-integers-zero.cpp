class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)return 0;
        // Agar n already 0 hai, toh koi operation karne ki zarurat nahi hai.
        // Isliye answer directly 0 hai.


        vector<int>precomputeIfonebitset(32,0); //32 bits
        // precomputeIfonebitset[i] ka matlab:
        // "Agar sirf ith bit ON ho, eg: 10000, 0010000, 10 aisa kuch 
        // toh usko 0 banane ke liye minimum kitne operations lagenge?"
        //
        // Example:
        // i = 0 -> number = 1   -> answer = 1
        // i = 1 -> number = 2   -> answer = 3  (10 - 00) so 10-> 11 (by 1st) -> 01 -> 00 (3 operations)
        // i = 2 -> number = 4   -> answer = 7
        // i = 3 -> number = 8   -> answer = 15
        //
        // In values ko pehle calculate karke rakh rahe hain
        // taaki baad mein directly use kar sakein.
        // so formunla precompute[i] = 2*precompute[i-1] + 1; base case precompute[0] = 1;
        //precompute[0] means 0th bit bs ON h i.e  1 so 1 ko 0 bnane me 1 operation

        precomputeIfonebitset[0] = 1;
        // Sirf 0th bit ON hai:
        //
        // 1 = 1
        //
        // Operation:
        // 1 -> 0
        //
        // Isliye f[0] = 1.


        int i=1;
        while(i<32) {
            precomputeIfonebitset[i] = 2LL*precomputeIfonebitset[i-1]+1;
            i++;
        }
        /*
            now listen
            3201   3201 -- position
            1100 - 0000
            so its like ki 100 ko 000 kro and fir 1000-0000 kro
            so like
            
            f(1100 -> 0000) = f(1000->0000) - f(1000->1100)  see in notes
            f(1100 -> 0000) = f(1000->0000) - f(000->100)  see in notes
            f(1100 -> 0000) = f(1000->0000) - f(100->000)  see in notes

            now  can be written as
            f(1100) = f(3) - f(2);  //3 and 2 are 3rd bit ko 0 bnana

            if bigger example so
            f(110010) = f(5) - f(4) + f(1); alternate signs
        */

        int ans=0;int sign=1; 
        for(int i=31;i>=0;i--){
           int ithBit = (n&(1LL<<i));
            // Ye check karta hai ki n ka ith bit SET hai ya nahi.
            if(ithBit){
                // Agar ith bit SET hai,
                // toh us bit ki precomputed cost answer mein contribute karegi.
                if(sign>0)ans += (precomputeIfonebitset[i]);
                else ans -= precomputeIfonebitset[i];
                sign = sign*(-1); 
            }
        }


        return ans;
    }
};