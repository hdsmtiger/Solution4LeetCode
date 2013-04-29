class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	ListNode* node = head;

		while(node != NULL)
		{
			ListNode* nextNode = node->next;

			if(nextNode != NULL)
			{
				int temp = nextNode->val;
				nextNode->val = node->val;
				node->val = temp;
				node = node->next->next;
			}else
				node = node->next;

		}

		return head;
        
    }
};
