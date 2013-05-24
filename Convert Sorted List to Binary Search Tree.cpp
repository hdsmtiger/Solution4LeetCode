/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      int size = num.size();

    	if(size == 0)
			return NULL;

		vector< pair<int, int> > posQue;
		TreeNode *root = new TreeNode(num[size/2]);
		vector<TreeNode* > nodeQue;
		nodeQue.push_back(root);
		posQue.push_back(pair<int, int>(0, size/2 - 1));
		posQue.push_back(pair<int, int>(size/2 + 1, size - 1));
        
        int nodeSize = 0;
        int posSize = 0;

		while(nodeSize < size)
		{
			int qSize = nodeQue.size();
			for(int i=nodeSize; i<qSize; i++)
			{
				TreeNode *node = nodeQue[i];
				pair<int, int> leftPair = posQue[i * 2];
				if(leftPair.first <= leftPair.second)
				{
					TreeNode *leftNode = new TreeNode(num[ (leftPair.first + leftPair.second)/2 ]);
					posQue.push_back(pair<int, int>(leftPair.first, (leftPair.first + leftPair.second)/2 - 1));
					posQue.push_back(pair<int, int>((leftPair.first + leftPair.second)/2 + 1, leftPair.second));
					node->left = leftNode;
					nodeQue.push_back(leftNode);
				}
				//posQue.erase(posQue.begin());

				pair<int, int> rightPair = posQue[i * 2 + 1];
				if(rightPair.first <= rightPair.second)
				{
					TreeNode *rightNode = new TreeNode(num[ (rightPair.first + rightPair.second)/2 ]);
					posQue.push_back(pair<int, int>(rightPair.first, (rightPair.first + rightPair.second)/2 - 1));
					posQue.push_back(pair<int, int>((rightPair.first + rightPair.second)/2 + 1, rightPair.second));
					node->right = rightNode;
					nodeQue.push_back(rightNode);
				}
				//posQue.erase(posQue.begin());
				
				//nodeQue.erase(nodeQue.begin());
			}
            nodeSize = qSize;
			posSize = (qSize * 2);
		}

		return root;
        
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(head == NULL)
            return NULL;
        
        vector<int> num;
        while(head != NULL)
        {
            num.push_back(head->val);
            head = head->next;
        }
        
        return sortedArrayToBST(num);       
        
        
    }
};
