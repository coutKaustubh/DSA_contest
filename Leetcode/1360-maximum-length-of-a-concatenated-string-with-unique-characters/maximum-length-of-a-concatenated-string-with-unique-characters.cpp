class Solution {
public:

    void solve(vector<string>& arr, int index, string one, int& ans) {
        unordered_map<char, int> mp;
        bool possible=true;
        for (char ch : one) {
            if (mp[ch] > 0) {
                possible = false;
                break;
            }
            mp[ch]++;
        }
        if (!possible)
            return;
        ans = max(ans, (int)one.size());
        for (int i = index; i < arr.size(); i++) {
            string two = arr[i];
            bool canAdd = true;
            unordered_map<char, int> temp = mp;
            for (char ch : two) {
                if (temp[ch] > 0) {
                    canAdd = false;
                    break;
                }
                temp[ch]++;
            }

            if (canAdd) {
                solve(arr, i + 1, one + two, ans);

            }
        }
    }

    int maxLength(vector<string>& arr) {
        int ans = 0;
        solve(arr, 0, "", ans);
        return ans;
    }
};