// class Solution {
// public:
//     int minOperations(string s) {
//         int c=0;
//         int n=s.size();
//         if(s[0] == '1'){
//             for(int i=1;i<s.size();i++){
//                 if(!(i&1) && s[i] != '1')c++;
//                 if((i&1) && s[i] != '0')c++;
//             }
//         }
//         else{
//             for(int i=1;i<s.size();i++){
//                 if(!(i&1) && s[i] != '0')c++;
//                 if((i&1) && s[i] != '1')c++;
//             }
//         }

//         return c;
//     }
// };

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int start0 = 0;
        int start1 = 0;

        for(int i=0;i<n;i++) {
            char exp0 = !(i&1) ? '0' : '1';
            char exp1 = !(i&1) ? '1' : '0';

            if(s[i] != exp0) start0++;
            if(s[i] != exp1) start1++;
        }

        return min(start0, start1);
    }
};