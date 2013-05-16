class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        
        int rowflags[100], colflags[100];
        
        memset(rowflags, 0, sizeof(int)*100);
        memset(colflags, 0, sizeof(int)*100);
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j] == 0)
                {//mark each row
                    rowflags[i/32] = rowflags[i/32] | 1<<(i%32);
                    colflags[j/32] = colflags[j/32] | 1<<(j%32);
                }
            }
        
        for(int i=0; i<=row; i++)
            if( rowflags[i/32] >> i%32 & 1 == 1)
            {
                for(int j=0; j<col; j++)
                    matrix[i][j] = 0;
            }
            
        for(int i=0; i<=col; i++)
            if( colflags[i/32] >> i%32 & 1 == 1)
            {
                for(int j=0; j<row; j++)
                    matrix[j][i] = 0;
            }
        
        
    }
};
