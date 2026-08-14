class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        for(char c = 'a'; c <= 'z'; c++)freq[c] = 0;

        int l =0,r=0,mx=0;
        while(r<s.size()){
            freq[s[r]]++;
            while(freq[s[r]] > 2){
                freq[s[l]]--;
                l++;
            }
            mx = max(mx,r-l+1);
            r++;

        }
        return mx;
    }
};