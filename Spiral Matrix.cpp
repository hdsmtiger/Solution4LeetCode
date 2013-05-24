class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      vector<int> result;
		int row = matrix.size();
        if(row == 0)
            return result;
		if(row == 1)
			return matrix[0];
		int col = matrix[0].size();

		int top = 0, bottom=row - 1, left = 0, right = col - 1;

		while(top<=bottom && left<=right)
		{
			for(int i=left; i<=right&& left <= right && top<=bottom; i++)
				result.push_back(matrix[top][i]);
			top++;

			for(int i=top; i<=bottom&& left <= right && top<=bottom; i++)
				result.push_back(matrix[i][right]);

			right--;

			for(int i=right; i>=left&& left <= right && top<=bottom; i--)
				result.push_back(matrix[bottom][i]);

			bottom--;

			for(int i=bottom; i>=top && left <= right && top<=bottom; i--)
				result.push_back(matrix[i][left]);

			left++;
		}

		return result;
        
    }
};
