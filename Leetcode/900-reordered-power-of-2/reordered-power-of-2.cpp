class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> mp(11);

        for (int i = 0; i <= 29; i++) {
            int x = 1 << i;
            int digits = to_string(x).size();
            mp[digits].push_back(x);
        }

        int digits = to_string(n).size();

        vector<int> freqN(10, 0);

        while (n > 0) {
            freqN[n % 10]++;
            n /= 10;
        }

        for (int x : mp[digits]) {
            vector<int> freq(10, 0);
            int temp = x;

            while (temp > 0) {
                freq[temp % 10]++;
                temp /= 10;
            }

            if (freq == freqN)
                return true;
        }

        return false;
    }
};