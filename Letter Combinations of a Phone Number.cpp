class Solution {
public:

  void findCombinations(string digits, int start, int end, vector<char> charmap[10], string substring, vector<string> &result)
	{
		if(start > end)
		{
			result.push_back(substring);
			return;
		}

		char digit = digits.at(start);
		if(digit == '1')
			return findCombinations(digits, start + 1, end, charmap, substring, result);

		for(int i = 0; i<charmap[digit - '0'].size(); i++)
		{
			int digit_int = (digit - '0');
			substring.push_back(charmap[digit_int][i]);
			findCombinations(digits, start + 1, end, charmap, substring, result);
			substring.erase(substring.length() - 1);
		}

	}

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<char> charmap[10];
		vector<string> result;

		for(int i= 'a'; i< 's'; i++)
		{
			charmap[ (i - 'a')  / 3 + 2].push_back(i);
		}

		charmap[7].push_back('s');
		charmap[8].push_back('t');
		charmap[8].push_back('u');
		charmap[8].push_back('v');
		charmap[9].push_back('w');
		charmap[9].push_back('x');
		charmap[9].push_back('y');
		charmap[9].push_back('z');		
		charmap[0].push_back(' ');
		
		findCombinations(digits, 0, digits.length() - 1, charmap, "", result);



		return result;
        
    }
};
