class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
          int a[9][9]={0},b[9][9]={0},c[9][9]={0};
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board.size();++j){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
//  The character at the (i, j) position is first converted to its corresponding ASCII code, and then subtracting the ASCII code of '0' gives us the numerical value of the digit. For example, the ASCII code of '0' is 48, and the ASCII code of '5' is 53. Thus, '5' - '0' gives 5, the numerical value of the digit.

// However, since the valid range of numbers in the sudoku board is from 1 to 9, we subtract 1 from num to convert it to a valid index in the range of 0 to 8.

// For example, if the character at (i, j) position is '5', then num will be assigned a value of 4 (since 5 - '0' = 5, and 5 - 1 = 4).                   
                    int k= i / 3 * 3 + j / 3;
                    if(a[i][num]||b[j][num]||c[k][num]){
                        return false;
                    }
                        a[i][num]=b[j][num]=c[k][num]=1;
                }

            
            }

        }
        return true;
    }
};