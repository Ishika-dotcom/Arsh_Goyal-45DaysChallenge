class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 1;
        int y = 1;

        for(int j=0;j<n;j++){            // for checking if first row(marker) contains 0 then x=0
            if(matrix[0][j]==0){
                x=0;
            }
        }

        for(int i=0;i<m;i++){            //for checking if first column(marker) contains 0 then y=0
            if(matrix[i][0]==0){
                y=0;
            }
        }

        for(int i=1;i<m;i++){           //check if in the inner matrix 0 is there specifically mark 0 in the first row & col(marker)
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int j=1;j<n;j++){      //check where the marker is 0 & update the whole inner matrix's row & col as 0
            if(matrix[0][j]==0){          //for row
                for(int i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){         //same as above for col
            if(matrix[i][0]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }

        if(y==0){                         //check if x & y are 0 then update the first row & col(marker) as 0
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }

        if(x==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
    }
};