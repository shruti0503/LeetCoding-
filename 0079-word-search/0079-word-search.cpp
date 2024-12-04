class Solution {
public:
   bool dfs(vector<vector<char>>& board, int i, int j, int index, string word){
       if(index==word.length()) return true;
       if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }


       //mark the cell as visited
       char temp=board[i][j];
       board[i][j]='#' ;

       bool found= dfs(board, i+1, j,index+1,word )||
                   dfs(board, i, j+1, index+1, word)||
                   dfs(board, i-1, j, index+1, word)||
                   dfs(board, i, j-1, index+1, word);
        board[i][j]=temp;
        return found;

            
   }
    bool exist(vector<vector<char>>& board, string word) {


        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                if( dfs(board,i, j, 0 , word)){
                    return true;
                }

            }
        }


        return false;



      
        
    }
};