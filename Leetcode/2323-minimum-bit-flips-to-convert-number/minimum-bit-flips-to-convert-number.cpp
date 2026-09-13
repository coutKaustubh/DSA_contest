class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor = (start^goal); // Xor means if 2 bit diff so 1 else 0 eg: a^a = 0 and a^b = 1
        int c=0;
        while(Xor!=0){
            Xor = Xor&(Xor-1);
            c++;
        }
        return c;
    }
};