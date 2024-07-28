class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if(matrix.empty() || matrix[0].empty()){
            return result;
        }

        int n = matrix.size();       // number of rows
        int m = matrix[0].size();    // number of columns
        int row_st = 0, row_e = n - 1, col_st = 0, col_e = m - 1;

        while(row_st <= row_e && col_st <= col_e) {
            // Traverse from left to right along the top row
            for(int col = col_st; col <= col_e; col++) {
                result.push_back(matrix[row_st][col]);
            }
            row_st++;
            
            // Traverse from top to bottom along the right column
            
            for(int row = row_st; row <= row_e; row++) {
                result.push_back(matrix[row][col_e]);
            }
            col_e--;
            

            // Traverse from right to left along the bottom row
            if(row_st <= row_e) {
                for(int col = col_e; col >= col_st; col--) {
                    result.push_back(matrix[row_e][col]);
                }
                row_e--;
            }

            // Traverse from bottom to top along the left column
            if(col_st <= col_e) {
                for(int row = row_e; row >= row_st; row--) {
                    result.push_back(matrix[row][col_st]);
                }
                col_st++;
            }
        }

        return result;
    }
};

