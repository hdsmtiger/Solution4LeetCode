class Solution {
public:

  void matches(const char *s, const char *p, bool &result, int indexs, int indexp, int lengtha, int lengthp)
	{
		if(indexs == lengtha && indexp == lengthp)
		{
			result = true;
			return;
		}

		//check next character is star or not
		bool isStar = false;
		if(indexp + 1 < lengthp)
			isStar = p[indexp+1] == '*';

		if(!isStar) // if it is not star, just check text if it is same
		{
			if(p[indexp] == '.')
				matches(s, p, result, indexs+1, indexp+1, lengtha, lengthp);
			else
			{
			    if (s[indexs] != p[indexp])
					return;
				matches(s, p, result, indexs+1, indexp+1, lengtha, lengthp);
			}
		}else
		{
			if(p[indexp] == '.')
			{
				for(int i=indexs; result == false && i<=lengtha; i++)
				{
					matches(s, p, result, i, indexp+2, lengtha, lengthp);
				}


			}else
			{
				matches(s, p, result, indexs, indexp+2, lengtha, lengthp); //test 0 matches first.
				for(int i=indexs; result == false && i<=lengtha;i++)
				{
					if (s[i] != p[indexp])
						return;
					matches(s, p, result, i+1, indexp+2, lengtha, lengthp);
				}

			}

		}
	}

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
		int  lengtha, lengthp, i;

		for(i = 0; s[i] != '\0'; i++);
		lengtha = i;

		for(i = 0; p[i] != '\0'; i++);
		lengthp = i;

		if(lengthp == 0 && lengtha == 0)
			return true;

		bool result = false;

		matches(s, p, result, 0, 0, lengtha, lengthp);

		

		return result;
		
		
    }
};
