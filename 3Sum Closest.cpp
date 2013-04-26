class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result, i, j, k;
        int length = num.size();
        std::sort(num.begin(), num.end());
  	result = num[0] + num[1] + num[length - 1];
        for(int i = 0; i<length - 2; i++)
		{
			j = i+1;
			k = length - 1;
			while(j < k)
			{
				if( abs(num[i] + num[j] + num[k] - target) < abs(result - target))
				{
					result = num[i] + num[j] + num[k];
				}
				if(result == target) return result;

				if(num[i] + num[j] + num[k] < target)
					j++;
				else
					k--;

			}
		}
        return result;
    }
};
