class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      int steps[100][100];
		for(int i=0;i<100;i++)
			for(int j=0; j<100;j++)
				steps[i][j] = 0;

		steps[0][0] = 1;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{

				if(i-1>=0)
					steps[i][j] += steps[i-1][j];
				if(j-1>=0)
					steps[i][j] += steps[i][j-1];
			}

		return steps[m-1][n-1];        
    }
};
