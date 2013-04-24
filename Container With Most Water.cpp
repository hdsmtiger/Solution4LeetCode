class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      int length = height.size();
        int maxAr = 0;
		int curAr = 0;

		for(int i=0, j=length-1; i<j; )
		{
			curAr = (j-i) * min(height[j], height[i]);
			if(curAr>maxAr)
				maxAr = curAr;

			if(height[j]>height[i])
				i++;
			else j--;
		}

		return maxAr;

    }
};
