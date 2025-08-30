class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // check each row
    for (int i = 0; i < 9; i++) {
        vector<bool> used(9, false);
        for (int j = 0; j < 9; j++) {
            char val = board[i][j];
            if (val == '.') {
                continue;
            }
            int index = val - '1';
            if (used[index]) {
                return false;
            }
            used[index] = true;
        }
    }

    // check each column
    for (int j = 0; j < 9; j++) {
        vector<bool> used(9, false);
        for (int i = 0; i < 9; i++) {
            char val = board[i][j];
            if (val == '.') {
                continue;
            }
            int index = val - '1';
            if (used[index]) {
                return false;
            }
            used[index] = true;
        }
    }

    // check each 3x3 sub-box
    for (int box_row = 0; box_row < 3; box_row++) {
        for (int box_col = 0; box_col < 3; box_col++) {
            vector<bool> used(9, false);
            for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
                for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
                    char val = board[i][j];
                    if (val == '.') {
                        continue;
                    }
                    int index = val - '1';
                    if (used[index]) {
                        return false;
                    }
                    used[index] = true;
                }
            }
        }
    }

    return true;
}


};