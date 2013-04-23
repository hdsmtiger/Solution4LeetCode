class Solution {
public:

  bool isPalindrome(string s, int start, int end)
	{
		int i = start;
		int j = end;
		for(; i<j; i++, j--)
		{
			if(s.at(i) != s.at(j) )
				return false;
		}

		return true;
	}

	void calcAllSubPalindrome(string s, int start, int end, vector<string> part, vector<int>* flags, vector<vector<string>>& result)
	{

		if(start > end)
		{
			result.push_back(part);
			return;
		}

		vector<int>::reverse_iterator it = flags[start].rbegin();

		while(it != flags[start].rend())
		{

			part.push_back(s.substr(start, (*it) - start + 1));

			calcAllSubPalindrome(s, (*it)+1, end, part, flags, result);

			part.pop_back();

			it++;
		}

	}
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function


		int length = s.length();
		
		vector<int>* flags = new vector<int>[length];
		
		for(int i=0; i<length; i++)
		{
			//first of all, calculate even p
			int left = i;
			int right = i+1;

			flags[i].push_back(i);;

			for(;left>=0 && right<length; left--, right++ )
			{
				if(s.at(left) == s.at(right))
					flags[left].push_back(right);
				else
					break;
			}

			//then calculate odd
			for(left= i-1, right = i+1;left>=0 && right<length; left--, right++)
			{
				if(s.at(left) == s.at(right))
					flags[left].push_back(right);
				else
					break;
			}

		}

		//put all sub p into vector.

		//flags[0].pop_back();

		vector<vector<string>> part;

		vector<int>::reverse_iterator it = flags[0].rbegin();

		while(it != flags[0].rend())
		{
			vector<string> temp;


			temp.push_back(s.substr(0, *it + 1));

			calcAllSubPalindrome(s, (*it)+1, length - 1, temp, flags, part);

			temp.pop_back();
			
			it++;
		}

		delete [] flags;

		return part;
        
    }
	
};
