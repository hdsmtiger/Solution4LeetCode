class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<int, vector<int>, greater<int> > pQueue;
      map<int, int> existingMap;

		int length = num.size();
		if(length == 0)
			return 0;

		for(int i=0; i<length; i++)
		{
			if(existingMap.find(num[i]) == existingMap.end() )
			{
			    pQueue.push(num[i]);
				existingMap.insert( pair<int, int>(num[i], 1) );
			}
		}

		int longestC = 1;
		int count = 1;
		int n = pQueue.top();
		pQueue.pop();
		int m;
		while(!pQueue.empty())
		{
			m = pQueue.top();
			pQueue.pop();
			if(m - n == 1)
			{
				count++;
			}else
			{
				if(count > longestC)
					longestC = count;
				count = 1;
			}

			n = m;
		}

		if(count > longestC)
			longestC = count;

		return longestC;
    }
};
