class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int* count = new int[n + 1];
        count[0] = 1;
        count[1] = 1;

        int i = 2;
        
        for(i = 2;i<=n; i++)
        {
            count[i] = 0;
            
            for(int k=0; k<=i-1; k++)
      		count[i] += count[k] * count[i-1-k];
        }
        
        return count[n];
    }
};
