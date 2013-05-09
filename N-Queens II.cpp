#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

  bool isValidQueue(int** queues, int n, int row, int column)
	{
		//check column
		for(int i=0; i<row; i++)
			if(queues[i][column] == 1)
				return false;
		for(int i=row-1, j = column - 1; i>=0 && j>=0; i--, j--)
			if(queues[i][j] == 1)
				return false;

		for(int i=row - 1, j=column + 1; i>=0&&j<n; i--, j++)
			if(queues[i][j] == 1)
				return false;

		return true;
	}

	void findNextQueue(int** queues, int row, int &result, int n)
	{
		if(row == n)
		{
			result++;
			return;
		}
		for(int i=0; i<n; i++)
		{
			if(isValidQueue(queues, n, row, i))
			{
				queues[row][i] = 1;
				findNextQueue(queues, row + 1, result, n);
				queues[row][i] = 0;

			}
		}
	}

     int totalNQueens(int n) {
        
		int result = 0;

		int** queues = new int*[n];
		for(int i=0; i<n; i++)
			queues[i] = new int[n];

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				queues[i][j] = 0;


		for(int i=0; i<n; i++)
		{
			queues[0][i] = 1;
			findNextQueue(queues, 1, result, n);
			queues[0][i] = 0;
		}

		return result;        
    }
};
//
//
//void main()
//{
//	int result;
//
//	Solution s;
//
//	result = s.totalNQueens(8);
//
//	cout<<result<<endl;
//
//	getchar();
//}
