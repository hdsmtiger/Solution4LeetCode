#include <iostream>
using namespace std;
// * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL) 
  		return head;

		int val;
		bool compareValue = false;
		
		ListNode *node = NULL;

		if(head->val == head->next->val)
		{
			//delete both node;
			val = head->val;
			node = head->next;
			delete head;
			head = node;
			node = head->next;
			delete head;
			head = node;

			while(head != NULL)
			{
				if(head->val == val)
				{
					ListNode *node = head;
					head = head->next;
					delete node;
				}else if(head->next != NULL)
				{
					if(head->val == head->next->val)
					{
						val = head->val;
						ListNode *node = head;
						head = head->next;
						delete node;
						node = head;
						head = head->next;
						delete node;
					}else
					{
						break;
					}
				}else
					return head;
			}
		}
			

		if(head == NULL || head->next == NULL)
			return head;

		ListNode *prevNode, *nextNode;
		prevNode = head;
		nextNode = head->next;
		val = head->val;
		while(nextNode!=NULL)
		{
			if(nextNode->val == val)
			{
				ListNode *node=nextNode;
				nextNode = nextNode->next;
				delete node;
				prevNode->next = nextNode;
			}else if(nextNode->next != NULL)
			{
				if(nextNode->val == nextNode->next->val)
				{//delete both of them
					val = nextNode->val;
					ListNode *node = nextNode;
					nextNode = nextNode->next;
					delete node;
					node = nextNode;
					nextNode = nextNode->next;
					delete node;
					prevNode->next = nextNode;
				}else
				{
					prevNode = nextNode;
					nextNode = nextNode->next;
				}
			}else
				nextNode = nextNode->next;
		}

		return head;

    }
};
//
//void main()
//{
//	int A[] = {1,2};
//
//	ListNode *head = new ListNode(A[0]);
//	ListNode *preNode = head;
//    ListNode *node = NULL;
//	for(int i=1;i<2;i++)
//	{
//		node = new ListNode(A[i]);
//		preNode->next = node;
//		preNode = preNode->next;
//	}
//
//	Solution s;
//	ListNode *result = s.deleteDuplicates(head);
//
//	while(result != NULL)
//	{
//		cout<<result->val<<",";
//		result = result->next;
//	}
//
//	getchar();
//}
