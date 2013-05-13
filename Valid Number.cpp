#include "header.hpp"

class Solution {
public:

  int findNumber(const char *s, int begin)
	{
		int i = begin;
		bool numberChecked = false;
		bool dotChecked = false;
		if(s[begin] == '+' || s[begin] == '-')
			i++;
		while(s[i] != '\0')
		{
			if( s[i] >= '0' && s[i] <='9')
			{
				numberChecked = true;
				i++;
			}else if( s[i] == '.')
			{
				if(dotChecked == true)
					return -1;
				else
				{
					dotChecked = true;
					i++;
				}
			}else
			{
				if(numberChecked == false)
			        return -1;
				else
					return i;
			}
				
		}
		if(numberChecked == false)
			        return -1;
		return i;
	}

	int findNumberAfterE(const char *s, int begin)
	{
		int i = begin;
		bool numberChecked = false;
		if(s[begin] == '+' || s[begin] == '-')
			i++;
		while(s[i] != '\0')
		{
			if( s[i] >= '0' && s[i] <='9')
			{
				numberChecked = true;
				i++;
			}else if(s[i] == ' ')
				return i;
			else
				return -1;
		}

		if(numberChecked == false)
			return -1;
		return i;
	}

    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int i = 0;

		while(s[i] != '\0' && s[i] == ' ')
		{//trim blank before string
				i++;
		}

		int pos = findNumber(s, i);
		if(pos == -1)
			return false;

		if(s[pos] == '\0')
			return true;
		else if(s[pos] == 'e')
		{
			pos = findNumberAfterE(s, pos+1);
			if(pos == -1)
				return false;
			else if(s[pos] == '\0')
				return true;
			else
			{
				while(s[pos] != '\0')
				{
					if(s[pos] != ' ')
						return false;
					pos++;
				}
				return true;
			}
		}else if(s[pos] == ' ')
		{
			while(s[pos] != '\0')
			{
				if(s[pos] != ' ')
					return false;
				pos++;
			}
			return true;
		}


		return false;
    }
};

//void main()
//{
//	Solution s;
//
//	if(s.isNumber("1a"))
//		cout<<"yes"<<endl;
//	else cout<<"no"<<endl;
//
//	getchar();
//}
