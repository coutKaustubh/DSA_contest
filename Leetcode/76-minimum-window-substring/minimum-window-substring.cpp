class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t)
            mp[c]++;
        int l = 0, r = 0;
        int count = 0;
        int mini = INT_MAX;
        int start = -1;
        while (r < s.size()) {
            if (mp.find(s[r]) != mp.end()) {
                if (mp[s[r]] > 0)
                    count++;
                mp[s[r]]--;
            }
            while (count == t.size()) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }
                if (mp.find(s[l]) != mp.end()) {
                    mp[s[l]]++;
                    if (mp[s[l]] > 0)
                        count--;
                }
                l++;
            }
            r++;
        }

        return start==-1 ?"": s.substr(start,mini);
    }
};