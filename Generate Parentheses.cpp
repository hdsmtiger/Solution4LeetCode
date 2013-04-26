class Solution {
public:

  void genParenthesis(stack<char> pStack, int n, int left,int right, vector<string> &result, string output)
	{
		if(left == n)
		{
			for(int i=right; i<n;i++)
			{
				output.push_back(')');
			}
			result.push_back(output);
			return;
		}

	    pStack.push('(');
		output.push_back('(');
		genParenthesis(pStack, n, left + 1,right, result,output);
		pStack.pop();
		output.erase(output.length() - 1);

		if(!pStack.empty())
		{
			pStack.pop();
			output.push_back(')');
			genParenthesis(pStack, n, left, right + 1,result,output);
		}
	}


    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> pStack;
		vector<string> result;
		string output;

		if(n==0)
			return result;

		pStack.push('(');
		output.push_back('(');

		genParenthesis(pStack, n, 1, 0, result, output);

		return result;
    }
};
