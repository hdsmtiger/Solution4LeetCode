#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int steps[100][100];
		for(int i=0;i<100;i++)
			for(int j=0; j<100;j++)
				steps[i][j] = 0;

		int m= obstacleGrid.size();
		int n= 0;
		if(m == 0)
			return 0;
		n = obstacleGrid[0].size();

		if(obstacleGrid[0][0] == 1)
			return 0;
		steps[0][0] = 1;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				if(obstacleGrid[i][j] == 1)
					continue;

				if(i-1>=0)
					steps[i][j] += steps[i-1][j];
				if(j-1>=0)
					steps[i][j] += steps[i][j-1];
			}

		return steps[m-1][n-1];        
    }
};

//void main()
//{
//	int m,n;
//	cin>>m>>n;
//	Solution s;
//	cout<<s.uniquePaths(m,n)<<endl;
//
//	getchar();
//}
