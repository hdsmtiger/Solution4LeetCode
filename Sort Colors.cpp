class Solution {
public:

  void swap(int A[], int indexa, int indexb)
	{
		int temp = A[indexa];
		A[indexa] = A[indexb];
		A[indexb] = temp;
	}

	int partition(int A[], int begin, int end, int pivotIndex)
	{
		int pivotValue = A[pivotIndex];
		swap(A, pivotIndex, end);
		int newPivot = begin;
		int i=begin;

		while(i<end)
		{
			if(A[i] <= pivotValue)
			{
				swap(A, i, newPivot);
				newPivot++;
			}
			i++;
		}
		swap(A, newPivot, end);

		return newPivot;

	}

	void quick_sort(int A[], int begin, int end)
	{
		if(begin >= end)
			return;
		int middle = (begin + end) / 2;

		int newPivot = partition(A, begin, end, middle);

		quick_sort(A, begin, newPivot - 1);
		quick_sort(A, newPivot+1, end);

	}
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		quick_sort(A, 0, n-1);        
    }
};
//
//void main()
//{
//
//	int A[]={1};
//
//	Solution s;
//	s.sortColors(A, 16);
//
//	for(int i=0; i<16; i++)
//		cout<<A[i]<<" ";
//	getchar();
//}
