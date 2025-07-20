class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colo=1;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                colo=0;

            }
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = row - 1; i >= 0; i--) {
    for (int j = col - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (colo == 0) {
      matrix[i][0] = 0;
    }

  }
        
    }
};