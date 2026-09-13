class Solution {
public:
    char findTheDifference(string s, string t) {
        int XORs=0,XORt=0;
        for(auto x:s) XORs=XORs^(int)x;
        for(auto x:t) XORs=XORs^(int)x;
        return XORt^XORs;
        

    }
};