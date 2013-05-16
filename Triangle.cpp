#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	int* row = new int[triangle.size()];
		for(int i=0; i<triangle.size(); i++)
			row[i] = 0;
		int minS = triangle[0][0];
		row[0] = triangle[0][0];
		for(int i=1; i<triangle.size(); i++)
		{
			minS = INT_MAX;
			for(int j=triangle[i].size() - 1; j>=0; j--)
			{
					if(j == triangle[i].size() - 1)
						row[j] = row[j-1] + triangle[i][j];
					else if(j == 0)
						row[j] = row[j] + triangle[i][j];
					else
						row[j] = min(row[j - 1] + triangle[i][j], row[j] + triangle[i][j]);

				if(row[j] < minS)
					minS = row[j];
			}
		}
		return minS;
        
    }
};

//void main()
//{
//	vector<vector<int> > triangle;
//	vector<int> row1;
//	vector<int> row2;
//	row1.push_back(1);
//	row2.push_back(2);
//	row2.push_back(3);
//	triangle.push_back(row1);
//	triangle.push_back(row2);
//	Solution s;
//	s.minimumTotal(triangle);
//}
