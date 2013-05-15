class Solution {
public:

  string parseWord(string path, int &index, int length)
	{
		bool findWords = false;
		string word;
		index++;
		while(index < length)
		{
			if(path.at(index) == '/')
				break;
			else
				word.push_back(path.at(index++));
		}
		return word;
	}
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		stack<string> stackStr;
		int length = path.size();
		int i = 0;

		if(length <= 0)
			return "";

		do{
			string word = parseWord(path, i, length);
			if(word == "..")
			{
				if(!stackStr.empty())
					stackStr.pop();
			}else if(word == ".")
				continue;
			else if(word.size() > 0)
			{
				stackStr.push(word);
			}

		}while(i<length);

		if(stackStr.empty())
			return "/";

		string result;
		while(!stackStr.empty())
		{
			result.insert(0, "/"+stackStr.top());
			stackStr.pop();
		}

		

		return result;

        
    }
};

//void main()
//{
//	Solution s;
//	string str;
//	while(cin>>str)
//	{
//	cout<<s.simplifyPath(str)<<endl;
//	}
//	getchar();
//}
