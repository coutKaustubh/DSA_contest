class Solution {
public:
    int minFlips(int a, int b, int c) {
        int num=1,ct=0;
        while (num <= a || num <= b || num <= c){
            if((c&num) != 0){
                if((a&num) ==0 && (b&num)==0)ct++;
            }
            else{
                if((a&num) !=0 && (b&num)!=0)ct+=2;
                else if ((a&num) ==0 && (b&num)==0){}
                else ct++;
            }
            num<<=1;
        }
        return ct;
    }
};