class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0;
        int r = min((int)s.size()-1,9);
        unordered_map<string,int>freq;
        while(r<s.size()){
            freq[s.substr(l,10)]++;
            r++;
            l++;
        }
        vector<string>ans;
        for(auto x:freq){
            if(x.second > 1)ans.push_back(x.first);
        }
        
        return ans;

    }
};