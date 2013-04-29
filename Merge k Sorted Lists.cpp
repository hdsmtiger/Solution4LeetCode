class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

  	int length = lists.size();
		ListNode** position = new ListNode*[length];
		ListNode* header = NULL;
		ListNode* prevNode = NULL;
		int minValue = INT_MAX;
		int nodeNum;

		for(int i=0; i<length; i++)
		{
			position[i] = lists[i];
		}

		
		while(true)
		{
			nodeNum = -1;
			minValue = INT_MAX;
			for(int i=0; i<length; i++)
			{
				if(position[i] != NULL)
				{
					if(minValue > position[i]->val)
					{
						minValue = position[i]->val;
						nodeNum = i;
					}
				}
				
			}

			if(nodeNum < 0)
				break;
			
			if(header == NULL)
			{
			    header = new ListNode(position[nodeNum]->val);
				prevNode = header;
			}
			else
			{
				ListNode* node = new ListNode(position[nodeNum]->val);
				prevNode->next = node;
				prevNode = node;
			}

			position[nodeNum] = position[nodeNum]->next;

		}

		delete [] position;

		return header;        
    }
};
