class Solution {
public:

  string string_add(string num1, string num2)
	{
		int lth1 = num1.length();
		int lth2 = num2.length();

		int i=0;
		int highbit = 0;
		string result;
		while(i<lth1 || i<lth2)
		{
			int sum = 0;
			sum += highbit;
			if(i<lth1)
				sum += (num1.at(i) - '0');
			if(i<lth2)
				sum += (num2.at(i) - '0');

			highbit = sum / 10;
			result.push_back(sum%10 + '0');

			i++;
		}

		if(highbit != 0)
			result.push_back(highbit + '0');

		return result;

	}

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(num1 == "0" || num2 == "0")
			return "0";

		string result;

		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());

		int lth1 = num1.length();
		int lth2 = num2.length();
		
		for(int i=0; i<lth1; i++)
		{
			string oneBitMultipy;
			
			int highbit = 0;
			for(int j=0; j<lth2; j++)
			{
				int multipy = 0;
				multipy += highbit;
				multipy += (num1.at(i) - '0') * (num2.at(j) - '0');

				highbit = multipy / 10;
				oneBitMultipy.push_back(multipy % 10 + '0');
			}

			if(highbit != 0)
			     oneBitMultipy.push_back(highbit + '0');

			for(int k=0; k<i; k++)
				oneBitMultipy.insert(0, "0");

			result = string_add(result , oneBitMultipy);
		}

		std::reverse(result.begin(), result.end());
		

		return result;
        
    }
};
