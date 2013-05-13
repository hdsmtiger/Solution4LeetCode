class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          	
		int m= grid.size();
		int n= 0;
		if(m == 0)
			return 0;
		n = grid[0].size();
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				//if(steps[i][j] = grid[i][j])

				int minimal = INT_MAX;

				if(i-1>=0 && grid[i-1][j]+grid[i][j] <minimal)
					minimal = grid[i][j] + grid[i-1][j];
				if(j-1>=0 && grid[i][j-1] + grid[i][j] < minimal)
					minimal = grid[i][j-1] + grid[i][j];
				if(minimal != INT_MAX)
					grid[i][j] = minimal;
			}

		return grid[m-1][n-1];    

    }
};
