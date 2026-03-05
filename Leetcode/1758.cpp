class Solution {
public:
    int minOperations(string s) {
        int c=0;
        int n=s.size();
        if(s[0] == '1'){
            for(int i=1;i<s.size();i++){
                if(!(i&1) && s[i] != '1')c++;
                if((i&1) && s[i] != '0')c++;
            }
        }
        else{
            for(int i=1;i<s.size();i++){
                if(!(i&1) && s[i] != '0')c++;
                if((i&1) && s[i] != '1')c++;
            }
        }

        return c;
    }
};