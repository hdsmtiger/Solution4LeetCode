class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int jc[10];
		jc[0] = 1;
		for(int i=1; i<10; i++)
			jc[i] = jc[i-1] * i;

		string charpool = "123456789";

		k--;
		string result;
		while(n>=1)
		{
			int pos = k/jc[n-1];
			result.push_back(charpool.at(pos) );
			charpool.erase(charpool.begin() + pos);
			k= k % jc[n-1];
			n--;
		}

		return result;
    }
};
