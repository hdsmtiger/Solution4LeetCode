class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = s.length();
        if(length <= 1)
            return s;
            
        string result;
        for(int i=0; i<length; i++)
        {
            int left = i, right = i+1;
            int stop = 0;
            for(; left>=0 && right <length; left--, right++)
            {
                if(s.at(left) != s.at(right) )
                {
                    break;
                }
            }
            
            
            string temp = s.substr(left+1, right-1 - left);
            if(temp.length() > result.length())
                result = temp;
            
            
            left = i-1, right = i+1;
            for(; left>=0 && right <length; left--, right++)
            {
                if(s.at(left) != s.at(right))
                {
                    break;
                }
            }
            
            temp = s.substr(left+1, right-1 - left);
            if(temp.length() > result.length())
                result = temp;
        
        }
        
        return result;
    }
};
