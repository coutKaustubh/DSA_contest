class Solution {
public:
    void paran(string &s,vector<string>&ans,int n,int open,int close){
        if(open == 0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            paran(s,ans,n,open-1,close);
            s.pop_back();

        }
        if(close>0){
            if(close>open){
                s.push_back(')');
                paran(s,ans,n,open,close-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        int open=n,close=n;
        paran(s,ans,n,open,close);

        return ans;
    }
};