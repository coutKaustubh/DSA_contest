class Solution {
public:
    void helperMap(string &s){
        vector<pair<char,int>> freq;
        for(int i = 0; i < s.size(); ) {
            char ch = s[i];
            int cnt = 0;
            while(i < s.size() && s[i] == ch) {
                cnt++;
                i++;
            }

            freq.push_back({ch, cnt});
        }
        s="";
        for(auto [x,y]:freq){
            s += (to_string(y));
            s.push_back(x);
        }

    }
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans = "1";
        for(int i=2;i<=n;i++){
            helperMap(ans);
        }
        return ans;
    }
};