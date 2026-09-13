class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto x:s)freq[x]++;
        vector<pair<char, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans="";
        for(auto [x,y]:v){
            for(int i=0;i<y;i++){
                ans+=x;
            }
        }
        return ans;                                                              
    }
};