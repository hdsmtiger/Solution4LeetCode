class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector< vector<int> > result;
        if(n ==0)
            return result;
            
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<n; j++)
                row.push_back(0);
            result.push_back(row);
        }
        
        int count = 1;
        int top = 0, bottom=n - 1, left = 0, right = n - 1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left; i<=right&& left <= right && top<=bottom; i++)
            result[top][i] = count++;
            top++;
            
            for(int i=top; i<=bottom&& left <= right && top<=bottom; i++)
            result[i][right] = count++;
            
            right--;
            
            for(int i=right; i>=left&& left <= right && top<=bottom; i--)
            result[bottom][i] = count++;
            
            bottom--;
            
            for(int i=bottom; i>=top && left <= right && top<=bottom; i--)
            result[i][left] = count++;
            
            left++;
        }
        
        return result;
        
    }
};
