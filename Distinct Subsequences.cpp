class Solution {
public:

  

    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int lengthS = S.size();
		int lengthT = T.size();
		if(lengthS < lengthT)
			return 0;


		int indexS =0, indexT = 0;

		long long* lastcount = new long long[lengthS+1];
		long long* curcount = new long long[lengthS+1];
		lastcount[lengthS] = 0;
		curcount[lengthS] = 0;
		for(int i=lengthS - 1; i>=0; i--)
		{
			lastcount[i] = lastcount[i+1];
			if(S.at(i) == T.at(lengthT-1))
			    lastcount[i]++;
			curcount[i] = 0;
		}

		for(int i=2; i<=lengthT; i++)
		{
			curcount[lengthS - i + 1] = 0;
			for(int j=lengthS-i; j>=0; j--)
			{
				curcount[j] = curcount[j+1];
				if(T.at(lengthT - i) == S.at(j))
				{
					curcount[j] += lastcount[j+1];
				}
			}

			long long* temp = curcount;
			curcount = lastcount;
			lastcount = temp;
		}
		return lastcount[0];
    }
};
