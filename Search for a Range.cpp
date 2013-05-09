
class Solution {
public:

  int binary_search(int A[], int begin, int end, int target)
	{
		int middle = (begin + end) / 2;
		while(begin<=end)
		{
			if(A[middle] == target)
				return middle;
			if(A[middle] > target)
				end = middle - 1;
			else
				begin = middle + 1;
			middle = (begin + end) / 2;
		}

		return -1;
	}

	void findMin(int A[], int begin, int end, int target, int& min)
	{
		int position = binary_search(A, begin, end, target);
		if(position == -1)
			return;
		min = position;
		findMin(A, 0, position - 1, target, min);
	}

	void findMax(int A[], int begin, int end, int target, int& max)
	{
		int position = binary_search(A, begin, end, target);
		if(position == -1)
			return;
		max = position;
		findMax(A, position+1, end, target, max);
	}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<int> result;
		int min = INT_MAX;
		int max = INT_MIN;

		int position = binary_search(A, 0, n-1, target);
        
		min = position;
		max = position;

		if(position == -1)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		findMin(A, 0, position-1, target, min);
		findMax(A, position+1, n-1, target, max);

		result.push_back(min);
		result.push_back(max);
    }
};
