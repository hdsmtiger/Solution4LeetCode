#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board, int row, int col, char num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int length = board.size();

		//first check row
			//strcpy(flags, "");
		for(int j=0; j<length; j++)
		{
			if( board[row][j] == num)
				return false;
		}
		for(int j=0; j<length; j++)
		{
			if( board[j][col] == num)
				return false;
		}

		for(int i= (row/3) * 3; i<(row/3) * 3 + 3; i++)
			for(int j= (col/3) * 3; j<(col/3) * 3 + 3; j++)
				if(board[i][j] == num)
					return false;

		return true;
    }

	void tryNextPosition(vector<vector<char> > &board, int indexR, int indexC, bool& found)
	{
		int i = indexR, j=indexC, findDot = 0;

		while(i< 9 && j<9)
		{
			if(board[i][j] == '.')
			{
				findDot = 1;
				break;
			}
			i = i + (j+1)/9;
			j = (j+1) % 9;
		}

		if(findDot == 0)
		{
			found = 1;
			return;
		}

		int k=0;
		for(int k=0; k<9 && !found ; k++)
		{
			
			if(isValidSudoku(board, i, j, k+'1'))
			{
				board[i][j] = '1' + k;
				tryNextPosition(board, i+(j+1)/9, (j+1)%9, found);
			}

			if(!found)
				board[i][j] = '.';
		}
	}

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		bool found = false;
		for(int i=0; i<9 && !found; i++)
			for(int j=0; j<9 && !found; j++)
			{
				if(board[i][j] == '.')
				{
					for(int k=0; k<9 && !found; k++)
					{
						
						if(isValidSudoku(board, i, j, k+'1'))
						{
							board[i][j] = '1' + k;
					        tryNextPosition(board, i+(j+1)/9, (j+1)%9, found);
						}
						//board[i][j] = '.';
					}
				}
			}
    }
};

//void main()
//{
//	char flags[100];
//
//	Solution s;
//
//	char sudoku[9][10] = {".....7..9",".4..812..","...9...1.","..53...72","293....5.",".....53..","8...23...","7...5..4.","531.7...."};
//	//["53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"] ["534678912","672195348","198342567","859761423","426853791","713924856","961537284",".87419635",".45286179"] ["534678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179"] 
// 
//	vector< vector<char> > sudokuVector;
//
//	for(int i=0; i<9; i++)
//	{
//		vector<char> oneColumn;
//		for(int j=0; j<9; j++)
//		{
//			oneColumn.push_back(sudoku[i][j]);
//		}
//		sudokuVector.push_back(oneColumn);
//	}
//
//
//	s.solveSudoku(sudokuVector);
//
//
//	for(int i=0; i<9; i++)
//	{
//		
//		for(int j=0; j<9; j++)
//		{
//			cout<<sudokuVector[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//
//	cout<<flags[90];
//
//	getchar();
//}
