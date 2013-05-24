class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int row = board.size();
		if(row == 0)
			return;

		int col = board[0].size();

		if(row <=2 || col <=2)
			return;

		vector< pair<int, int> > dots;
		for(int i=0; i<row; i++)
		{
			if(board[i][0] == 'O')
			{
				board[i][0] = 'Y';
				dots.push_back(pair<int, int> (i, 0));
			}

			if(board[i][col-1] == 'O')
			{
				board[i][col-1] = 'Y';
				dots.push_back(pair<int, int> (i, col - 1));
			}
		}

		for(int i=1; i<col - 1; i++)
		{
			if(board[0][i] == 'O')
			{
				board[0][i] = 'Y';
				dots.push_back(pair<int, int> (0,i));
			}

			if(board[row-1][i] == 'O')
			{
				board[row-1][i] = 'Y';
				dots.push_back(pair<int, int> (row - 1, i));
			}
		}

		while(!dots.empty())
		{
			pair<int, int> dot = dots[0];
			dots.erase(dots.begin());

			//check up
			if(dot.first - 1 >=0 && board[dot.first - 1][dot.second] == 'O')
			{
				dots.push_back(pair<int, int> (dot.first-1, dot.second));
				board[dot.first - 1][dot.second] = 'Y';
			}

			//check dowm
			if(dot.first + 1 < row && board[dot.first + 1][dot.second] == 'O')
			{
				dots.push_back(pair<int, int> (dot.first + 1, dot.second));
				board[dot.first + 1][dot.second] = 'Y';
			}

			//check left
			if(dot.second - 1 >=0 && board[dot.first][dot.second - 1] == 'O')
			{
				dots.push_back(pair<int, int>(dot.first, dot.second-1));
				board[dot.first][dot.second - 1] = 'Y';
			}

			//check right
			if(dot.second + 1 < col && board[dot.first][dot.second + 1] == 'O')
			{
				dots.push_back(pair<int, int>(dot.first, dot.second + 1));
				board[dot.first][dot.second + 1] = 'Y';
			}
		}

		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
			{
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == 'Y')
					board[i][j] = 'O';
			}
    }
};
