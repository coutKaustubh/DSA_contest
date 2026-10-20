class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(auto x:bills){
            if(x==5)five++;
            else if(x==10){
                if(five < 1)return false;
                five =five-1;
                ten = ten+1;
            }
            else{
                if(five >= 1 && ten >= 1){
                    five = five-1;
                    ten = ten-1;
                }
                else if(five >= 3){
                    five = five-3;
                }
                else return false;
            }

        }
        return true;
    }
};