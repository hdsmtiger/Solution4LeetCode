#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
  	map<string, pair<string, int> > strMap;

		int length = strs.size();

		for(int i=0; i<length; i++)
		{
			string temp = strs[i];
			std::sort(temp.begin(), temp.end());
			map<string,pair<string, int> >::iterator it = strMap.find(temp);
			if(it == strMap.end())
			{
				strMap.insert(pair<string, pair<string, int> >(temp, pair<string, int>(strs[i], 0)));
			}else
			{
				//result.push_back(it->second);
				if(it->second.second == 0)
				{
					result.push_back(it->second.first);
					it->second.second = 1;
				}
				result.push_back(strs[i]);
			}
			
		}


        return result;
    }
};
