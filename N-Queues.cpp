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

	vector<string> turnToVector(int** queues, int n)
	{
		vector<string> result;
		for(int i=0; i<n; i++)
		{
			string row;
			for(int j=0; j<n; j++)
				if(queues[i][j] == 0)
					row.push_back('.');
				else row.push_back('Q');
			result.push_back(row);
		}
		return result;
	}

	void findNextQueue(int** queues, int row, vector<vector<string> > &result, int n)
	{
		if(row == n)
		{
			result.push_back(turnToVector(queues, n));
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

    vector<vector<string> > solveNQueens(int n) {
        
		vector<vector<string> > result;

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


//void main()
//{
//	vector< vector<string> > result;
//
//	Solution s;
//
//	result = s.solveNQueens(8);
//
//	for(int i=0; i<result.size(); i++)
//	{
//		for(int j=0; j<result[i].size(); j++)
//			cout<<result[i][j]<<endl;
//
//		cout<<"**************"<<endl;
//	}
//
//	getchar();
//}
