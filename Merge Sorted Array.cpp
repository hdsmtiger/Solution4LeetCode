class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int inda=0, indb=0;
        for(int i=0; i<m+n && indb<n; i++)
        {
            if(i<m+indb && A[i] < B[indb])
                continue;
            else
            {
                for(int j=m+indb; j>i; j--)
                {
                    A[j] = A[j-1];
                }
                A[i] = B[indb++];
            }
        }
        
    }
};
