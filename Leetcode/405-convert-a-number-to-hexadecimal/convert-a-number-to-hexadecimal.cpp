class Solution {
public:
    typedef long long ll;
    string toHex(int num) {
        vector<char> hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string ans = "";
        ll k = num;
        if (num < 0)
            k = pow(2, 32) + k;
        // isse kya ho rha lets say k=-1
        // so hmlog 2^32-1 kr rhe jisse kya hoga ab ye number jo h voh 32bit unsigned bn gya mtlb ab bs is number ko normal number maano and iska hexadecimal nikalo...kyuki at the wnd 2's compliment krne pr iska hi binary bnta +1 = 00000000 00000000 00000000 00000001 and fir iska 2's hota 11111111 11111111 11111111 11111111
        // 32 bits ko groups of 4 mein divide:
//1111 1111 1111 1111 1111 1111 1111 1111
    // iska representation ffffffff 
        if (k == 0)
            return "0";
        while (k != 0) {
            int rem = k % 16;
            int q = k / 16;
            k = q;
            ans += hexDigits[rem];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};