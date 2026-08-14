class Solution {
public:
    int atoiFun(string &s) {
        long long ans = 0;
        int n = s.size();

        if (s.empty())
            return 0;

        int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;

        for (int i = start; i < n; i++) {
            int digit = s[i] - '0';

            // Check BEFORE ans = ans * 10 + digit
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {

                if (s[0] == '-')
                    return INT_MIN;
                else
                    return INT_MAX;
            }

            ans = ans * 10 + digit;
        }

        return s[0] == '-' ? -ans : ans;
    }

    int myAtoi(string s) {
        string final = "";

        int i = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            final += s[i];
            i++;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            final += s[i];
            i++;
        }

        return atoiFun(final);
    }
};