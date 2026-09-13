class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        sort(v.begin(), v.end());
        string first = v[0];
        string last = v[v.size()-1];
        string ans="";
        for(int i=0;i<first.size();i++){
            if(first[i] == last[i])ans+=first[i];
            else break;
        }
        return ans;
    }
};