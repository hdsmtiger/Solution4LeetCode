class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int length = s.length();
        if(length <= 1)
            return length;
        
  	char flags[30];
		

        int max = 0;
        int curr = 0;
        for(int i=0; i<length; i++)
        {
			memset(flags, 0, sizeof(char) * 30);
			for(int j=i; j<length; j++)
			{
				if( flags[s.at(j) - 'a'] != 1)
				{
					curr++;
					flags[s.at(j) - 'a']  = 1;
				}
				else
					break;
				
			}
			if(max < curr)
			{
				max = curr;
				
			}

			curr = 0;
        
        }
        
        return max;
    }
};
