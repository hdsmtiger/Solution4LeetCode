#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
      stack<char> pStack;
		int i, length;
		length = s.length();
		for(i = 0; i<length; i++)
		{
			char character = s.at(i);
			if(character == '(' || character == '[' || character == '{')
				pStack.push(character);
			else if(character == ')' || character == ']' || character == '}')
			{
				if( !pStack.empty())
				{
					if(character == ')' && pStack.top() == '(' ||
						character == ']' && pStack.top() == '[' ||
						character == '}' && pStack.top() == '{')
					{
					    pStack.pop();
					}
					else return false;
				}
				else return false;
			}
		}

		return pStack.empty();
    }
};
