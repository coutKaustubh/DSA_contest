// class Solution {
// public:
//     bool checkOnesSegment(string s) {
//         int c=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i] == '1')c++;
//             else c=0;
//             if(c==2)return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool checkOnesSegment(string s) {
        int c=0;
        if(s.size() == 1 && s[0] == '1')return true;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1')c++;
            else c=0;
            if(c==2)return true;
        }
        return false;
    }
};