class Solution {
public:
// for first queen can place in anty row of first colimn. 
//  for every queen that i place in the board , i have to=>
   // 1. check  if its safe to put the queen there :
        // check upper elemnt 
        // check down element
        // check vertical elemnt
        // check horizontal element

   // 2. call the recursive function for others as well

  bool isSafe(int row, int col, vector<string> board, int n){
     int drow=row;
     int dcol=col;
     while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;

     }
     row=drow;
     col=dcol;
     while(row>=0 and col>=0){
        if(board[row][col]=='Q') return false;
            row--;
            col--;
       }
       row=drow;
       col=dcol;
    while(row<n and col>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row++;
    }
    row=drow;
    col=dcol;
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }
    return true;


  }

  void func(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col]='Q'; // it is safe to put queen 
            func(col+1, board, ans, n); // move to next column
            board[row][col]='.'; // backtrack to further analyse other possible situations
        }
    }
  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> row(n, string(n,'.'));
        func(0, row, ans, n);
        return ans;
        
    }
};