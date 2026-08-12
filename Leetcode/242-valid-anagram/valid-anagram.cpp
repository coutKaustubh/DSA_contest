class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char>st1;
        multiset<char>st2;
        for(auto x:s)st1.insert(x);
        for(auto x:t)st2.insert(x);

        return st1==st2;
    }
};