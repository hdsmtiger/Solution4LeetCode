#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
  	vector<int> processed;

		int signflag = -1;
		int sum = 0;
		int result = INT_MIN;
		for(int i=0; i<n; i++)
		{
			if(A[i] >= 0 && signflag == -1)
			{
				if(sum != 0)
					processed.push_back(sum);
				sum = 0;
				signflag = 1;
			}else if(A[i] <0 && signflag == 1)
			{
				if(sum != 0)
					processed.push_back(sum);
				sum = 0;
				signflag = -1;
			}

			if(A[i]>result)
				result = A[i];

			sum += A[i];
		}

		processed.push_back(sum);
		
		
		int* sumArr = new int[n];
		
		for(int i=0; i<processed.size(); i++)
				sumArr[i] = 0;

		for(int i=0; i<processed.size(); i++)
		{
			sumArr[i] = processed[i];
			if(processed[i] > result)
				result = processed[i];
		}

		for(int i=2; i<=processed.size(); i++)
		{
			int sum = 0;
			for(int j=0; j+i-1<processed.size();j++)
			{
				sumArr[j] = sumArr[j] + processed[j+i-1];
				if(sumArr[j] > result)
					result = sumArr[j];
			}

		}



		return result;


    }
};

//void main()
//{
//	int A[] = {1,2,-1,-2,2,1,-2,1,4,-5,4};
//
//	Solution s;
//	cout<<s.maxSubArray(A, 11)<<endl;
//	getchar();
//}
