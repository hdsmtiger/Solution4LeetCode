class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(str == NULL)
      	return 0;
            
        long long result = 0;
        int i=0;
        int sign = 1;
        for(i=0; str[i] != '\0'; i++)
        {//remove blank
            if(str[i] == ' ' )
                continue;
            else
                break;
        }
        
        if(str[i] == '+')
            i++;
        else if(str[i] == '-')
        {
            i++;
            sign = -1;
        }
        
        for(; str[i] != '\0'; i++)
        {
            
            if(str[i] <= '9' && str[i] >= '0')
            {
                result *= 10;
                result = result + str[i] - '0';
            }
            else
                break;
        }
        
        result = result * sign;
        
        if(result > INT_MAX)
            result = INT_MAX;
        
        if(result < INT_MIN)
            result = INT_MIN;
        
        return result;
        
    }
};
