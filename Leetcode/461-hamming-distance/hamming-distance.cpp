class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = x^y;
        int c=0;
        while(d){
            c++;
            d = d&(d-1);
        }
        return c;
    }
};