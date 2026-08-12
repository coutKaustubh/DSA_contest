class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int mx=0;
        for(auto x:s){
            if(x=='(')depth++;
            else if(x==')')depth--;
            mx = max(mx,depth);
        }
        return mx;
    }
};