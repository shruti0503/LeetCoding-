class Solution {
public:
// observe that first col of the original matrix is reversal of the lkast column of the matrix
// so next app-> transpose the matrix
// then reverse each row
// sc -> O(1)
    void rotate(vector<vector<int>>& matrix) {
        // step 1 swap
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){ // note here the condition j<i
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // step 2 reverse each row of the matrix
        for(int i=0;i<matrix.size(); i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};