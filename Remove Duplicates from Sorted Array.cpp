class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int duplicate = 0;
		for(int i=1; i<n; i++)
		{
			if(A[i] == A[i-1])
			{
				duplicate++;
			}
			else
			{
				A[i-duplicate] = A[i];
			}
		}        

		return n-duplicate;
    }
};
