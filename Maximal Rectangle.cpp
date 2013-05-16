class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int row = matrix.size();
		if(row == 0)
			return 0;

		int col = matrix[0].size();

		int** xx = new int*[row];
		for(int i=0; i<row; i++)
			xx[i] = new int[col];

		int** left = new int*[row];
		for(int i=0; i<row; i++)
			left[i] = new int[col];

		int** right = new int*[row];
		for(int i=0; i<row; i++)
			right[i] = new int[col];

		for(int i=0; i<col; i++)
			if(matrix[0][i] == '1')
			    xx[0][i] = 1;
			else xx[0][i] = 0;

		for(int i=1; i<row; i++)
			for(int j=0; j<col; j++)
				if(matrix[i][j] == '0')
					xx[i][j] = 0;
				else
					xx[i][j] = xx[i-1][j] + 1;

		int max_size = 0;

		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
			{
				if(xx[i][j] == 0)
				{
					left[i][j] = 0;
					right[i][j] = 0;
				}else
				{
					int k = j - 1;
					left[i][j] = 0;
					for(; k>=0; k--)
					{
						if(matrix[i][k] == '0')
							break;
						left[i][j] = left[i][j] + 1 ;
					}
					if(i-1>=0 && matrix[i-1][j] != '0')
					    left[i][j] = min(left[i][j], left[i-1][j]);

					k = j + 1;
					right[i][j] = 0;
					for(; k<col; k++)
					{
						if(matrix[i][k] == '0')
							break;
						right[i][j] = right[i][j] + 1;
					}

					if(i-1 >= 0 && matrix[i-1][j] != '0')
						right[i][j] = min(right[i][j], right[i-1][j]);

					int size = (left[i][j] + right[i][j] + 1) * xx[i][j];
					if(size > max_size)
						max_size = size;
				}
			}

			return max_size;        
    }
};
