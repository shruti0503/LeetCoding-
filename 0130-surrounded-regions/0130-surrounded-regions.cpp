class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int n, int m){
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O') return;
        board[row][col] = 'T';
        dfs(board, row - 1, col, n, m);
        dfs(board, row + 1, col, n, m);
        dfs(board, row, col + 1, n, m);
        dfs(board, row, col - 1, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();  

       
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(board, i, 0, n, m);
            if(board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') dfs(board, 0, i, n, m);
            if(board[n - 1][i] == 'O') dfs(board, n - 1, i, n, m);  
        }

       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
