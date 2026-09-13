class Solution {
public:
    string longestPrefix(string s) {
        int pref=0,suff=1;
        int n = s.size();
        if (n == 0)
            return "";
        vector<int>LPC(n,0); //longest prefix-suffix combination by KMP method
        LPC[0] = 0;
        while(suff<n){
            if(s[pref] == s[suff]){
                LPC[suff] = pref+1;
                suff++;
                pref++;
            }
            else{
            //     int actualsuff=suff;
            //     int c=0;
            //     while(pref>=0){
            //         if(s[pref] != s[suff]){
            //             pref--;
            //             c=0;
            //             suff = actualsuff;
            //         }
            //         else{
            //             pref--;
            //             suff--;
            //             c++;
            //         }
            //     }
            //     pref = c;
            //     LPC[actualsuff] = c;
            //     suff = actualsuff+1;
            // }

            if(pref == 0){
                LPC[suff] = 0;
                suff++;
            }
            else
                pref = LPC[pref-1];
            }
        } 
        int size = LPC[n-1];

        return s.substr(0,size);
    } 
};