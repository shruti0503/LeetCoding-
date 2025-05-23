class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    // Check for every number from '1' to '9' if we can place it in this cell
                    for (char c = '1'; c <= '9'; c++) {
                        if (isvalid(board, i, j, c)) {
                            board[i][j] = c;
                            // Place it and make a further recursion call
                            if (solveSudokuHelper(board, n, m)) {
                                return true;
                            } else {
                                board[i][j] = '.'; // Backtrack
                            }
                        }
                    }
                    // If no valid number can be placed, return false
                    return false;
                }
            }
        }
        return true; // All cells are filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        solveSudokuHelper(board, n, m);
    }
};
