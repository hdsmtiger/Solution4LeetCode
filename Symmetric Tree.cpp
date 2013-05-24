class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool result = true;
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
				TreeNode *node = nodeQue[0];
				
                if(node != NULL)
				{
					nodeQue.push_back(node->left);
					nodeQue.push_back(node->right);
				}
				nodeQue.erase(nodeQue.begin());
			}

			size = nodeQue.size();
			for(int i=0; i<(size / 2); i++)
			{
				if(nodeQue[i] == NULL && nodeQue[size-i-1] != NULL ||
						nodeQue[i] != NULL && nodeQue[size-i-1] == NULL)
						return false;
				if(nodeQue[i] != NULL && nodeQue[size-i-1] != NULL && 
					nodeQue[size-i-1]->val != nodeQue[i]->val)
					return false;

			}
		}

		return true;
    }
};
