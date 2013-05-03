#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	string result = "1";
		
		for(int i=0; i<n - 1; i++)
		{
			string str2 = result;
			int length = result.size();
			result = "";
			for(int j=0;j<length;)
			{
				char c1 = str2.at(j);
				int count = 1;
				while(j+count <length)
				{
					if(str2.at(j+count) == c1)
						count++;
					else break;
				}
				result.push_back('0'+count);
				result.push_back(c1);
				j = j+count;
			}

		}

		return result;

        
    }
};
