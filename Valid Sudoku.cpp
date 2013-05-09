#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	int length = board.size();
		char flags[100] = "";

		//first check each row
		for(int i=0; i<length; i++)
		{
			memset(flags, 0, 100);
			//strcpy(flags, "");
			for(int j=0; j<length; j++)
			{
				if( board[i][j] == '.')
					continue;
				if(flags[board[i][j] - '0'] == 1)
					return false;
				else
					flags[board[i][j] - '0'] = 1;
			}
		}

		//first check each column
		for(int i=0; i<length; i++)
		{
			memset(flags, 0, 100);
			for(int j=0; j<length; j++)
			{
				if( board[j][i] == '.')
					continue;
				if(flags[board[j][i] - '0'] == 1)
					return false;
				else
					flags[board[j][i] - '0'] = 1;
			}
		}

		for(int i=0; i< length / 3; i++)
		{
			
			for(int j=0; j<length/3; j++)
			{
				memset(flags, 0, 100);
				for(int k = i*3; k< (i+1)*3;k++)
				{
					for(int l = j*3; l<j*3+3; l++)
					{
						if( board[k][l] == '.')
							continue;
						if(flags[board[k][l] - '0'] == 1)
							return false;
						else
							flags[board[k][l] - '0'] = 1;
					}
				}
			}
		}

		return true;
		
    }
};

//void main()
//{
//	char flags[100];
//
//	Solution s;
//
//	char sudoku[9][10] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
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
//	s.isValidSudoku(sudokuVector);
//
//	cout<<flags[90];
//
//	getchar();
//}
