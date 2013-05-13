class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      if(k==0 || head == NULL ) return head;

		ListNode* head1 = head;
		ListNode* rear1 = head;
		ListNode *head2=NULL, *rear2 = NULL;

		int length = 0;
		while(head1!=NULL)
		{
			head1 = head1->next;
			length++;
		}

		head1 = head;

		k = length -  k % length;

		while(k-->0)
		{
			rear1 = head;
			if(head == NULL)
				return head1;
			head = head->next;
		}

		if(head == NULL)
			return head1;

		head2 = head;

		while(head!=NULL)
		{
			rear2 = head;
			head = head->next;
		}

		rear2->next = head1;
		rear1->next = NULL;

		return head2;
        
    }
};
