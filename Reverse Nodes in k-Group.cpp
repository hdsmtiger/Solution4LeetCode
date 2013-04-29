class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	ListNode *result = NULL;
		ListNode *preGroup = NULL, *curGroup = NULL, *nextGroup = NULL;
		ListNode *curNode=head, *prevNode=NULL, *nextNode=NULL;

		curGroup = head;
		nextGroup = head;



		while(true)
		{
			//ListNode* node = nextGroup;
			bool hasKLeft = true;
			curNode = nextGroup;
			for(int i=0; i<k; i++, nextGroup = nextGroup->next)
			{
				if(nextGroup == NULL)
				{
					hasKLeft = false;
					break;
				}
			}

			if(hasKLeft == false)
				break;

			ListNode *origNode = curNode;

			prevNode = curNode;
			curNode = curNode->next;
			if(curNode!=NULL)
			    nextNode = curNode->next;

			for(int i=0; i<k - 1; i++)
			{
				curNode->next = prevNode;
				prevNode = curNode;
				curNode = nextNode;
				if(nextNode!=NULL)
				    nextNode = nextNode->next;
			}
			
			origNode->next = curNode;

			if(preGroup == NULL)
			{
				result = prevNode;
				preGroup = origNode;
			}
			else
			{
				preGroup->next = prevNode;
				preGroup = origNode;
			}


		}

		if(result == NULL)
			return head;

		return result;
    }
};
