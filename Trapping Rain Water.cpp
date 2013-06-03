class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=2)
            return 0;
        
        int result = 0;
        
        for(int i=2; i<n; i++)
        {
            int top = A[i-1];
            if(A[i] <= top)
                continue;
            for(int j= i - 2; j>=0; j--)
            {
                if(A[j] > A[i])
                {
                    result += (A[i] - top) * (i - j - 1);
                    break;
                }
                
                if(A[j] > top)
                {
                    result += (A[j] - top) * (i - j - 1);
                    top = A[j];
                }
            }
        }
        
        return result;
    }
};
