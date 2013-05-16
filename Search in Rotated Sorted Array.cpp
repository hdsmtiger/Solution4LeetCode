using namespace std;
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 8,9,10,11, 12, 13,14, 15, 0 1 2).   1
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      int middle = n / 2, left = 0, right = n-1;


		while(left <= right)
		{
			if(A[middle] == target)
				return middle;

			if(target < A[left] && target > A[right])
			    return -1;

			if(A[left] <= A[right])
			{// normal binary search
				if(A[middle] > target)
					right = middle - 1;
				else left = middle + 1;
				
			}else
			{
				if(A[middle] >= A[left])
					if(target <= A[middle] && target >= A[left])
						right = middle - 1;
					else left = middle + 1;
				else
					if(target >= A[middle] && target <= A[right])
						left = middle + 1;
					else
						right = middle -1;

			}
			middle = (left + right) / 2;
		}


		return -1;
        
    }
};
