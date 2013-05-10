#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
     vector<Interval> merge(vector<Interval> &intervals) {


  	char flag[100000];
		memset(flag, 0, 100000);

		for(int i=0; i<intervals.size(); i++)
		{
			memset(flag+(intervals[i].start*2) + 1, 1, (intervals[i].end - intervals[i].start)*2 + 1);
		}

		vector<Interval> result;
		int firstNum = -1, secondNum = -1;
		for(int i=0; i<100000; i++)
		{
			if(firstNum != -1 && flag[i] == 0)
			{
				secondNum = i/2 - 1;
				result.push_back(Interval(firstNum, secondNum));
				firstNum = -1;
				secondNum = -1;

				continue;
			}else if(firstNum == -1 && flag[i] == 1)
				firstNum = i / 2 ;
		}

		return result;
	
    }
};

//
//void main()
//{
//	Solution s;
//	vector<Interval> ints;
//	ints.push_back(Interval(1,3));
//
//	vector<Interval> result = s.merge(ints);
//
//	for(int i=0; i<result.size(); i++)
//		cout<<result[i].start << ",  "<<result[i].end<<endl;
//
//	getchar();
//}
