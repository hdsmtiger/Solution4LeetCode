class Solution {
public:

    void checkNext(vector<vector<char> > &board, string word, int i, 
                      int j, int matchPos, bool &found, int row, int col)
    {
        if(matchPos >= word.size())
        {
            found = true;
            return;
        }
        
        if(!found && i-1 >=0 && board[i-1][j] == word.at(matchPos))
        {
            char temp = board[i-1][j];
            board[i-1][j] = 0;
            checkNext(board, word, i-1, j, matchPos + 1, found, row, col);
            board[i-1][j] = temp;
        }
        
        if(!found && i+1 < row && board[i+1][j] == word.at(matchPos))
        {
            char temp = board[i+1][j];
            board[i+1][j] = 0;
            checkNext(board, word, i+1, j, matchPos + 1, found, row, col);
            board[i+1][j] = temp;
        }
        
        if(!found && j-1 >=0 && board[i][j-1] == word.at(matchPos))
        {
            char temp = board[i][j-1];
            board[i][j-1] = 0;
            checkNext(board, word, i, j-1, matchPos + 1, found, row, col);
            board[i][j-1] = temp;
        }
        
        if(!found && j+1 < col && board[i][j+1] == word.at(matchPos))
        {
            char temp = board[i][j+1];
            board[i][j+1] = 0;
            checkNext(board, word, i, j+1, matchPos + 1, found, row, col);
            board[i][j+1] = temp;
        }
        
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
        int col = 0;
        if(row != 0)
            col = board[0].size();
            
        int length = word.size();
        if(length == 0)
            return true;
        
        int matchPos = 0;
        bool found = false;
        for(int i=0; i<row && !found; i++)
            for(int j=0; j<col && !found; j++)
            {
                if(board[i][j] == word.at(matchPos))
  			{
					char temp = board[i][j];
					board[i][j] = 0;
                    checkNext(board, word, i, j, matchPos + 1, found, row, col);
					board[i][j] = temp;
				}
            }
            
        return found;
    }
};
