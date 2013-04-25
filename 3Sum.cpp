class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        int length = num.size();
      std::sort(num.begin(), num.end());
        for(int i = 0; i<length; i++)
            if(num[i]<=0)
            for(int j=i+1; j<length; j++)
                if(num[i]+num[j]<=0)
                for(int k=j+1;k<length; k++)
                {
                    if(num[i] + num[j] + num[k] == 0)
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
							result.push_back(find);
						}

                        
                    }
                }
        return result;
    }
};
