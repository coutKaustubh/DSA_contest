class Solution {
public:
    int recursiveApproachStoi(int i,long long result,int &sign , string &s){
        if (i >= s.size())return result * sign;
        if (s[i] < '0' || s[i] >'9')return result*sign;
        result = result * 10 + (s[i] - '0');
        if (result * sign > INT_MAX)return INT_MAX;
        if (result * sign < INT_MIN)return INT_MIN;
        return recursiveApproachStoi(i+1,result,sign,s);
    }
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        long long result = 0;
        return recursiveApproachStoi(i,result,sign,s);
    }
};