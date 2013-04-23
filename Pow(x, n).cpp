class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double MIN_DOUBLE = 0.00000000000000000001;
      
       if( abs(abs(x) - 1.0) <= MIN_DOUBLE)
		{
			if( x < 0 )
				return x * (n%2) ? (-1) : 1;
			else
				return x;
		}
        
        double result = 1.0;
    	if(n<0)
		{
			x = 1.0 / x;
			n *= -1;
		}
		for(int i=0; i<n && abs(result) >=MIN_DOUBLE; i++)
    		result *= x;

		return result;

    }
};
