class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<long long, vector<int>> mp;

        for (int i = 0; i < reservedSeats.size(); i++) {
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        int c = (n - mp.size()) * 2;
        for (auto x : mp) {
            sort(x.second.begin(), x.second.end());
            bool left = true;   
            bool mid = true;    
            bool right = true; 

            for (int seat : x.second) {
                if (seat >= 2 && seat <= 5)
                    left = false;
                if (seat >= 4 && seat <= 7)
                    mid = false;
                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right)
                c += 2;
            else if (left || mid || right)
                c += 1;
        }

        return c;
    }
};