#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = num.size() - 1;
        int swapPosA = -1;
  	int swapPosB = -1;
        for(; index - 1>=0; index--)
		{
			if(num[index - 1] < num[index])
			{
				swapPosA = index - 1;
				break;
			}
		}

		if(swapPosA == -1)
		{
			std::sort(num.begin(), num.end());
			return;
		}

		for(index = num.size() - 1; index>=0; index--)
		{
			if(num[swapPosA] < num[index])
				break;
		}


		int temp = num[swapPosA];
		num[swapPosA] = num[index];
		num[index] = temp;
		std::sort(num.begin() + swapPosA + 1, num.end());
    }
};
