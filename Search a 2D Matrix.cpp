class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	int m=matrix.size();
		
		if(m<=0) return false;

		int n = matrix[0].size();

		int length = m*n;

		int i, j;

		for(i=0, j=length - 1; i<=j; )
		{
			int median = matrix[ (i + j) / 2 / n][ (i+j) / 2 % n];
			if( median == target)
				return true;
			else if(median > target)
				j = (i+j) / 2-1;
			else i = (i+j) / 2+1;
		}

		return false;

    }
};
