#include "header.hpp"
// * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
  	ListNode *header=NULL, *previousNode=NULL, *nextNode=NULL;

		while(l1 != NULL || l2 != NULL)
		{
			int minimal = INT_MAX;
			if(l1==NULL)
			{// put l2 into list;
				if(previousNode == NULL)
				    previousNode = l2;
				else
				{
					previousNode->next = l2;
					previousNode = previousNode->next;
				}
				l2 = l2->next;
			}else if( l2 == NULL)
			{// put l1 into list;
				if(previousNode == NULL)
				    previousNode = l1;
				else
				{
					previousNode->next = l1;
					previousNode = previousNode->next;
				}
				l1 = l1->next;

			}else
			{//compare l1 and l2
				if(l1->val > l2->val)
				{//put l2 into list
					if(previousNode == NULL)
				    previousNode = l2;
					else
					{
						previousNode->next = l2;
						previousNode = previousNode->next;
					}
					l2 = l2->next;
				}else
				{
					if(previousNode == NULL)
				    previousNode = l1;
					else
					{
						previousNode->next = l1;
						previousNode = previousNode->next;
					}
					l1 = l1->next;
				}

			}
			if(header == NULL)
				header = previousNode;
		}

		return header;
    }
};
