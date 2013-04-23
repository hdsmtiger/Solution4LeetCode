class Solution {
public:

  int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) return 0;

		int i, j;

		int middlePosition = 0;
		int position;

		middlePosition = n / 2;
		for(i=0, j=n-1; i<=j;)
		{
			
			if(A[middlePosition] == target)
				return middlePosition;
			else if(A[middlePosition] < target)
			{
				position = middlePosition + 1;
				i = middlePosition + 1;
				
			}
			else
			{
				position = middlePosition;
				j = middlePosition - 1;
			}

			middlePosition = (i + j ) / 2;
		    

		}

		return position;
        
    }
};
