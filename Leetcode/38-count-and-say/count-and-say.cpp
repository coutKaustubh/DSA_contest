class Solution {
public:
    void helperMap(string &s) {
        string temp;
        for(int i = 0; i < s.size(); ) {
            char ch = s[i];
            int cnt = 0;

            while(i < s.size() && s[i] == ch) {
                cnt++;
                i++;
            }

            temp += to_string(cnt);
            temp.push_back(ch);
        }

        s = temp;
    }

    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++) {
            helperMap(ans);
        }
        return ans;
    }
};