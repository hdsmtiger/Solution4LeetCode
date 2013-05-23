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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >result;
        if(root == NULL)
            return result;
        
        queue<TreeNode* > nodeQue;
        nodeQue.push(root);
        
        
        
        while(!nodeQue.empty())
        {
            int size = nodeQue.size();
            vector<int> oneRow;
            for(int i=0; i<size; i++)
            {
                TreeNode *node = nodeQue.front();
                nodeQue.pop();
                oneRow.push_back(node->val);
                if(node->left != NULL)
                    nodeQue.push(node->left);
                if(node->right != NULL)
                    nodeQue.push(node->right);
            }
            result.push_back(oneRow);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;

    }
};
