class Solution {
public:

    bool search(int index, int i, int j, vector<vector<char>>& board, string word){
        if(index == word.size()){      //base condition (if you have visited all the characters)
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){   //(check for out of bound condition)
            return false;
        }

        bool ans = false;
        if(word[index] == board[i][j]){
            board[i][j] = '*';                        //mark as visited if it is equal
            ans = search(index+1, i+1, j, board, word) ||
                  search(index+1, i, j+1, board, word) ||         // check in all four directions
                  search(index+1, i-1, j, board, word) ||
                  search(index+1, i, j-1, board, word);

            board[i][j] = word[index];            //undo visited 
        }
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        bool ans = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){       //check if word exists in the board if yes it calls the search function
                if(word[index] == board[i][j]){
                    if(search(index,i,j,board,word)){
                        return true;
                    }
                }
            }
        }

        return ans;
    }
};