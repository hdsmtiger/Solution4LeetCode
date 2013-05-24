class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  	// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> >result;
		if(root == NULL)
			return result;

		vector<TreeNode* > nodeQue;
		nodeQue.push_back(root);

		bool reversal = false;

		while(!nodeQue.empty())
		{
			int size = nodeQue.size();
			vector<int> oneRow;
			for(int i=0; i<size; i++)
			{
				TreeNode *node;
				//if(reversal)
				//{
					node= nodeQue[size - i - 1];
					nodeQue.erase(nodeQue.begin() + size - i - 1);
				//}
				/*else
				{
					node = nodeQue[0];
					nodeQue.erase(nodeQue.begin());
				}*/
				oneRow.push_back(node->val);
				
				if(reversal)
				{
					if(node->right != NULL)
						nodeQue.push_back(node->right);
					if(node->left != NULL)
						nodeQue.push_back(node->left);
					
					
				}else
				{
					if(node->left != NULL)
						nodeQue.push_back(node->left);
					if(node->right != NULL)
						nodeQue.push_back(node->right);
				}
			}
			result.push_back(oneRow);
			reversal = !reversal;
		}

		return result;
	}
};
