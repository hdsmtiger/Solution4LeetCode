class Solution {
public:

    void findNextDigit(string s, int index, int numberPos, vector<string> &result, string oneSolution, int length)
  {
		if(index == length && numberPos == 4)
		{
			result.push_back(oneSolution);
			return;
		}else if(index == length || numberPos == 4)
			return;

		for(int i=1; i<=3 && i+index <= length; i++)
		{
			if( (length - index - i) > (3-numberPos) * 3)
				continue;
			string digitStr = s.substr(index, i);
			if(digitStr.size() > 1 && digitStr.at(0) == '0')
                continue;
			int digit = atoi(digitStr.c_str());
			if(digit <=255)
			{
				oneSolution.push_back('.');
				oneSolution.append(digitStr);
				findNextDigit(s, index+i, numberPos + 1, result, oneSolution,length);
				oneSolution.erase(index + numberPos - 1, i+1);
			}       
		}
		
	}
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = s.size();
        vector<string> result;
        if(length<4 || length>12)
            return result;

		string oneSolution;
		for(int i=1; i<=3; i++)
		{
			if( (length - i) > 9)
				continue;
			string digitStr = s.substr(0, i);
			if(digitStr.size() > 1 && digitStr.at(0) == '0')
                continue;
			int digit = atoi(digitStr.c_str());
			if(digit <=255)
			{
				oneSolution.append(digitStr);
				findNextDigit(s, i, 1, result, oneSolution,length);
				oneSolution.erase(0, i);
			}       
		}

		return result;
    }
};
