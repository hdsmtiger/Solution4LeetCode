#include <iostream>
//
//int cmp(const void* a, const void* b)
//{
//  return *(int*)a-*(int*)b;
//}

class Solution {
public:

	
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		//qsort(A, n, sizeof(int),cmp);

		int targets = 0;
		for(int i=0; i<n; i++)
		{
			if(A[i] == elem)
			{
				targets++;
			}
			else
			{
				A[i-targets] = A[i];
			}
		}        

		return n-targets;

    }
};

