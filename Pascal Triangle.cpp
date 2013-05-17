class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        for(int i=0; i<numRows; i++)
        {
            vector<int> oneR;
            oneR.push_back(1);
            for(int k=1; k<i; k++)
                oneR.push_back(result[i-1][k-1] + result[i-1][k]);
            if(i != 0)
                oneR.push_back(1);
            result.push_back(oneR);
        }
        
        return result;
    }
};
