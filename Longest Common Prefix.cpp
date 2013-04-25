#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = strs.size();
        if(length <=0)
            return "";

        string result;
        int index = 0;
        bool accepted = true;
        for(int i=0; i<strs[0].length() && accepted; i++)
        {
            
            for(int j=1; j<length && accepted; j++)
            {
                if(i >= strs[j].length())
                    accepted = false;
                else if(strs[0].at(i) != strs[j].at(i) )
                    accepted = false;
            }
            if(accepted)
                result.push_back(strs[0].at(i));
        }
        return result;
    }
};
