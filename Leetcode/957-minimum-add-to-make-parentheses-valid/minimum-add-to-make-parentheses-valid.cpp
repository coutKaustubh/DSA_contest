class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        for(auto x:s){
            if(x =='(')open++;
            else if(x ==')'&& open>0) open--;
            else close++;
        }
        return open+close;
    }
};