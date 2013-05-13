#include "header.hpp"


class Solution {
public:
  string addBinary(string a, string b) {
		int lth1 = a.length();
		int lth2 = b.length();

		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());

		int i=0;
		int highbit = 0;
		string result;
		while(i<lth1 || i<lth2)
		{
			int sum = 0;
			sum += highbit;
			if(i<lth1)
				sum += (a.at(i) - '0');
			if(i<lth2)
				sum += (b.at(i) - '0');

			highbit = sum / 2;
			result.push_back(sum%2 + '0');

			i++;
		}

		if(highbit != 0)
			result.push_back(highbit + '0');

		std::reverse(result.begin(), result.end());

		return result;
	}
};
