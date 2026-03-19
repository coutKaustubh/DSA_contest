class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string a, string b){
        if(a==b)return true;
        if(a.size()<=1)return false;
        string key = a + "#" + b;
        string temp1 = a;
        string temp2 = b;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if(temp1 != temp2) return mp[key] = false;
        if(mp.find(key) != mp.end())return mp[key];
        bool flag =false;
        int n =a.size();
        for(int i=1;i<n;i++){
            bool swapPart1 = solve(a.substr(0,i) , b.substr(n-i,i));
            bool swapPart2 = solve(a.substr(i,n-i) , b.substr(0,n-i));
            bool NoswapPart1 = solve(a.substr(0,i) , b.substr(0,i));
            bool NoswapPart2 = solve(a.substr(i,n-i) , b.substr(i,n-i));


            if((swapPart1 && swapPart2)|| (NoswapPart1 && NoswapPart2)){
                flag =true;
                break;
            }
        
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())return false;
        if(s1.empty() && s2.empty())return true;
        return solve(s1,s2);
    }
};