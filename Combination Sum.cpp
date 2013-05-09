#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

  void searchNextDigits(vector<int> &candidates, int index, int length, int target, int sum,
		vector<int> oneNode, vector<vector<int> > &result)
	{
		for(int i=index; i<length; i++)
		{
			if( sum + candidates[i] == target)
			{
				oneNode.push_back(candidates[i]);
				result.push_back(oneNode);
				return;
			}else if( sum+candidates[i] > target)
				return;
			else
			{
				oneNode.push_back(candidates[i]);
				searchNextDigits(candidates, i, length, target, sum + candidates[i], oneNode, result);
				oneNode.pop_back();
			}
		}
	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
		std::sort(candidates.begin(), candidates.end());

		int length = candidates.size();

		vector<int> oneNode;
		for(int i=0; i<length; i++)
		{
			if(candidates[i] > target)
				break;
			
			if(candidates[i] == target)
			{
				oneNode.push_back(candidates[i]);
				result.push_back(oneNode);
				oneNode.pop_back();
				continue;
			}


			oneNode.push_back(candidates[i]);

			searchNextDigits(candidates, i, length, target, candidates[i], oneNode, result);
			
			oneNode.pop_back();
		}

		return result;        
    }
};
//
//void main()
//{
//	int A[] = {2, 3, 6, 7};
//	
//	vector<int> candidates;
//	vector<vector<int> > result;
//
//	for(int i=0; i<4; i++)
//		candidates.push_back(A[i]);
//
//	Solution s;
//	result = s.combinationSum(candidates, 7);
//
//	for(int i=0; i<result.size(); i++)
//	{
//		for(int j=0; j<result[i].size(); j++)
//			cout<<result[i][j]<< ", ";
//
//		cout<<endl;
//	}
//
//	getchar();
//}
