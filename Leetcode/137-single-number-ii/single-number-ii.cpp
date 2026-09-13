class Solution {
public:
    /*
    nums = [4, 4, 4, 7, 7, 7, 10]
    4  = 0100
    4  = 0100
    4  = 0100

    7  = 0111
    7  = 0111
    7  = 0111

    10 = 1010

                 b3 b2 b1 b0
    4             0  1  0  0
    4             0  1  0  0
    4             0  1  0  0

    7             0  1  1  1
    7             0  1  1  1
    7             0  1  1  1

    10            1  0  1  0
                ------------
    count         1  6  4  3

    b3: 1 % 3 = 1
    b2: 6 % 3 = 0
    b1: 4 % 3 = 1
    b0: 3 % 3 = 0

    thats 1 0 1 0 = 10 which is ans
        
    */
    int singleNumber(vector<int>& nums) {
         int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int cnt = 0;

            for (int x : nums) {
                if ((x >> bit) & 1)
                    cnt++;
            }

            if (cnt % 3) ans |= (1 << bit); // ans ke us bit ko 1 kro
            }
            return ans;
    }
};