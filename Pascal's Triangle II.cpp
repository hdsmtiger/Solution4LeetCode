class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        for(int i=0; i<=rowIndex; i++)
        {
            result.push_back(1);
        }
        
        for(int i = 2; i<=rowIndex; i++)
            for(int j = i - 1; j> 0; j--)
                result[j] = result[j] + result[j-1];    
        
        
        return result;
        
        
    }
};
