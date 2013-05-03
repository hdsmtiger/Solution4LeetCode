#include <iostream>
using namespace std;


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int flags[100];
  	memset(flags, 0, sizeof(int) * 100);

		for(int i=0; i<n; i++)
		{
			if(A[i]<=0)
				continue;
			flags[A[i]/32] = flags[A[i]/32] | (1<<(A[i]%32));
		}

		for(int i=0; i<100; i++)
		{
			int j=0;
			if(i==0)
				j=1;
			for(;j<32; j++)
			{
				if( ((flags[i]>>j) & 1) == 0)
					return i * 32 + j;
			}
		}

		return 1;
    }
};
