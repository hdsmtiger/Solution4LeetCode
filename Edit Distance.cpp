class Solution {
public:

    int countMinDistance(string word1, string word2, map< pair<string,string>, int> &dict)
  {
		int l1 = word1.size();
        int l2 = word2.size();
        if(word1 == word2)
            return 0;
        
        if(l2 == 0)
            return l1;
        if(l1 == 0)
            return l2;

		map< pair<string,string>, int>::iterator it = dict.find( pair<string, string>(word1, word2));

		if(it != dict.end())
			return it->second;

        int result = INT_MAX;
        
        int i=0;
        
        int count = 0;
        
        for(; i<l1 && i<l2 && word1.at(i) == word2.at(i); i++)
        ;
        
        if(i == l1 || i == l2)
            return abs(l1-l2);
            
        if(l1 -i < l2 - i)
		{
			//try delete first
			int deleteCount = 1 + countMinDistance(word1.substr(i, l1-i), word2.substr(i+1, l2-i-1), dict);
			int replaceCount = 1 + countMinDistance(word1.substr(i+1, l1-i-1), word2.substr(i+1, l2-i-1), dict);
			if(deleteCount > replaceCount)
				result = replaceCount;
			else result = deleteCount;
			dict.insert(pair< pair<string, string>, int>( pair<string, string>(word1, word2), result));
			return result;
		}

		int addCount = 1 + countMinDistance(word1.substr(i+1, l1-i-1), word2.substr(i, l2-i), dict);
		int deleteCount = 1 + countMinDistance(word1.substr(i, l1-i), word2.substr(i+1, l2-i-1), dict);
		int replaceCount = 1 + countMinDistance(word1.substr(i+1, l1-i-1), word2.substr(i+1, l2-i-1), dict);

		if(result > addCount)
			result = addCount;
		if(result > deleteCount)
			result = deleteCount;
		if(result > replaceCount)
			result = replaceCount;
		
		dict.insert(pair< pair<string, string>, int>( pair<string, string>(word1, word2), result));
		return result;
	}


    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.size();
        int l2 = word2.size();
        if(word1 == word2)
            return 0;
        
        if(l2 == 0)
            return l1;
        if(l1 == 0)
            return l2;
        
        map< pair<string,string>, int> dict;
		return countMinDistance(word1, word2, dict);
        
    }
};
