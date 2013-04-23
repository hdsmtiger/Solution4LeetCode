// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	
		
		ListNode* root = NULL;
		ListNode* prevNode = NULL;

		int num1=0, num2=0, sum = 0;

		while(l1!=NULL || l2!=NULL)
		{
			
			if(l1==NULL)
				num1 = 0;
			else num1 = l1->val;

			if(l2 == NULL)
				num2 = 0;
			else num2 = l2->val;

			sum = sum + num1 + num2;

			ListNode* node = new ListNode(0);
			if(prevNode == NULL)
			{
				prevNode = node;
				root = prevNode;
			}
			else
			{
				prevNode->next = node;
			}
			
			node->val = sum % 10;
			sum = sum / 10;

			
			if(l1!=NULL)
			    l1 = l1->next;
			if(l2!=NULL)
			    l2 = l2->next;

			prevNode = node;
		}

		if(sum>0)
		{
			ListNode* node = new ListNode(sum);
			prevNode->next = node;
		}

		return root;
        
    }
};
