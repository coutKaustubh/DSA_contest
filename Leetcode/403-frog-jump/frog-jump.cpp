class Solution {
public:
    map<pair<int,int>, bool> dp;

    bool frog(int i, vector<int>& s, int k) {
        int n = s.size();

        if (i == n - 1) return true;

        if (dp.count({i, k})) return dp[{i, k}];

        for (int j = i + 1; j < n; j++) {
            int jump = s[j] - s[i];

            if (jump > k + 1) break;

            if (jump >= k - 1 && jump > 0) {
                if (frog(j, s, jump))
                    return dp[{i, k}] = true;
            }
        }

        return dp[{i, k}] = false;
    }

    bool canCross(vector<int>& s) {
        int n = s.size();

        if (n == 1) return true;
        if (s[1] != 1) return false;

        dp.clear();
        return frog(1, s, 1);
    }
};