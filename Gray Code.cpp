class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if(n<0)
            return result;
        else if(n == 0)
        {
            result.push_back(0);
        }else if(n > 0)
        {
            result.push_back(0);
            result.push_back(1);
            int sum = 1;
            for(int i=1; i<n; i++)
            {
                sum = sum * 2;
                int length = result.size();
                for(int j=length - 1; j>=0; j--)
                {
                    result.push_back(result[j]+sum);
                }
                
            }
        }
        
        return result;
    }
};
