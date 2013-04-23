class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        int length = s.length();
        if(s.empty())
            return "";

  	if(nRows <= 1)
			return s;
        
        string result;
        vector<char>* transforms = new vector<char>[nRows];
        
        for(int i=0; i<length;i++)
        {
            int y = i % (2*nRows - 2);
            
            if(y<nRows)
                transforms[y].push_back(s.at(i));
            else
                transforms[2*nRows - 2 - y].push_back(s.at(i));
        }
        
        for(int i=0; i<nRows; i++)
            for(int j=0; j<transforms[i].size(); j++)
                result.push_back(transforms[i][j]);
                
		delete [] transforms;

        return result;
        
    }
};
