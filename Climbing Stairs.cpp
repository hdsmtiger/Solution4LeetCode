class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 1) return 1;
        if( n == 2) return 2;
        
        int i=2;
        int n1 = 1, n2 = 2;
        while(i++<n)
        {
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        
        return n2;
    }
};
