#include <iostream>
#include <vector>
using namespace std;
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      ListNode* pos = head;
		vector<ListNode*> nodeArr;
		int length = 0;
		while(pos != NULL)
		{
			length++;
			nodeArr.push_back(pos);
			pos = pos->next;
		}
        
        if(n> length)
    		return head;

		if(n == length)
		{
			pos = head;
			head = head->next;
			delete pos;
		}else
		{
			pos = nodeArr[length-n];
			nodeArr[length-n-1]->next = pos->next;
			delete pos;
		}
		

		return head;
        
    }
};
