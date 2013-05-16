class Solution {
public:

    void findNextElement(vector<int> S, vector<vector<int> > &result, vector<int>oneS,
                       int index, int length)
    {
        while(index<length)
        {
            oneS.push_back(S[index]);
            result.push_back(oneS);
            findNextElement(S, result, oneS, index+1, length);
            oneS.pop_back();
  		index++;
        }
                   
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = S.size();
        vector<vector<int> > result;
        
        sort(S.begin(), S.end());
		vector<int> oneS;
		result.push_back(oneS);
        for(int i=0; i<length; i++)
        {
            
            oneS.push_back(S[i]);
            result.push_back(oneS);
            findNextElement(S, result, oneS, i+1, length);
            oneS.pop_back();
        }

        return result;
    }
};
