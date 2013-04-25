class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

  	int result = 0;

		map<string, int> strmap;
		typedef pair <string, int> String_Pair;


		strmap.insert(String_Pair("I", 1));
		strmap.insert(String_Pair("IV", 4));
		strmap.insert(String_Pair("V", 5));
		strmap.insert(String_Pair("IX", 9));
		strmap.insert(String_Pair("X", 10));
		strmap.insert(String_Pair("XL", 40));
		strmap.insert(String_Pair("L", 50));
		strmap.insert(String_Pair("XC", 90));
		strmap.insert(String_Pair("C", 100));
		strmap.insert(String_Pair("CD", 400));
		strmap.insert(String_Pair("D", 500));
		strmap.insert(String_Pair("CM", 900));
		strmap.insert(String_Pair("M", 1000));

		int i=0, length = s.length();

		while(i<length)
		{
			string temp;
			temp.push_back(s.at(i));
			if(i+1 < length)
			{
				temp.push_back(s.at(i+1));
			}
			if(strmap.find(temp)!=strmap.end())
			{
				result += strmap.find(temp)->second;
				i = i+2;

			}else if(temp.length() >= 2)
			{
				temp.erase(temp.length() -1, 1);
				result += strmap.find(temp)->second;
				i = i + 1;

			}
		}
        return result;
    }
};
