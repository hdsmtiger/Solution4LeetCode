/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      if(head == NULL || head->next == NULL) 
			return head;
		
		ListNode* previousNode = head;

		ListNode *nextNode = NULL;

		int val = head->val;

		while(previousNode->next!= NULL)
		{
			nextNode = previousNode->next;
			
			if(nextNode->val == val)
			{
				previousNode->next = nextNode->next;
				delete nextNode;
			}else
			{
				previousNode= nextNode;
				val = previousNode->val;
			}
		}

		return head;
        
    }
};
