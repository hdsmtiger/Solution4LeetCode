class Solution {
public:

    void swap(int A[], int indexa, int indexb)
    {
      int temp = A[indexa];
		A[indexa] = A[indexb];
		A[indexb] = temp;
	}
    
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<3)
            return n;
        int i = 2, count = 0, insertPos = 2;
        while(i<n)
        {
            if(A[i] == A[i-1 - count] && A[i] == A[i-2-count])
            {
                count++;
            }else
            {
                swap(A, insertPos, i);
                insertPos++;
            }
            i++;
        }
        
        return n-count;
    }
};
