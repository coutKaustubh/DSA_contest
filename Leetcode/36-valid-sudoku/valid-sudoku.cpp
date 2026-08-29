class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> all(10, 0);

        // Check rows
        for (int i = 0; i < 9; i++) {
            all.assign(10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (all[num] != 0)
                    return false;
                all[num] = 1;
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            all.assign(10, 0);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if (all[num] != 0)
                    return false;
                all[num] = 1;
            }
        }

        // Check 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                all.assign(10, 0);

                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {

                        if (board[row][col] == '.')
                            continue;

                        int num = board[row][col] - '0';

                        if (all[num] != 0)
                            return false;

                        all[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};