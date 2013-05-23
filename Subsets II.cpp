class Solution {
public:
    void findNextElement(vector<int> S, set< vector<int> > &vectorSet, vector<int>oneS,
  	int index, int length)
	{
		while(index<length)
		{
			oneS.push_back(S[index]);
			vectorSet.insert(oneS);
			findNextElement(S, vectorSet, oneS, index+1, length);
			oneS.pop_back();
			index++;
		}

	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int length = S.size();
		vector<vector<int> > result;

		set< vector<int> > vectorSet;
		

		sort(S.begin(), S.end());
		vector<int> oneS;
		result.push_back(oneS);
		for(int i=0; i<length; i++)
		{

			oneS.push_back(S[i]);
			vectorSet.insert(oneS);
			findNextElement(S, vectorSet, oneS, i+1, length);
			oneS.pop_back();
		}

		set< vector<int> >::iterator it = vectorSet.begin();
		while(it != vectorSet.end())
		{
			result.push_back( *it );
			it++;
		}

		return result;
	}
};
