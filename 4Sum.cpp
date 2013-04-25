class Solution {
public:

  //std::binary_search

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > result;
		int length = num.size();

		std::sort(num.begin(), num.end());
		for(int i = 0; i<length; i++)
		{
			if(0>target && num[i] > 0)
				break;
				for(int j=i+1; j<length; j++)
				{
					if( num[j] >=0 && num[i] >target)
				        break;
					
						for(int k=j+1;k<length; k++)
						{   
							if(num[k] >=0 && num[i] + num[j] >target)
								break;

							//binary search for the last
							int pos = std::binary_search(num.begin() + k + 1, num.end(), target - num[i]-num[j]-num[k]);

							if(pos)
							{
								bool shouldInsert = true;
								if(!result.empty())
									for(int l=0; l<result.size(); l++)
									{
										if(result[l][0] == num[i] && 
											result[l][1] == num[j] && 
											result[l][2] == num[k])
										{
											shouldInsert = false;
											break;
										}
									}

									if(shouldInsert)
									{
										vector<int> find;
										find.push_back(num[i]);
										find.push_back(num[j]);
										find.push_back(num[k]);
										find.push_back(target - num[i]-num[j]-num[k]);
										result.push_back(find);
									}

							}
						}         
				}
		}
		return result;
	}
};
