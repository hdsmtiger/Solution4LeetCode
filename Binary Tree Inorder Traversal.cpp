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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack< TreeNode* > nodeStack;
        vector<int> result;
        bool switcher = true;
        if(root != NULL)
        {
            while(!nodeStack.empty() || root != NULL)
            {
                if(root == NULL)
                {
                    root = nodeStack.top();
                    nodeStack.pop();
                    result.push_back(root->val);
                    root = root->right;
                    continue;
                }else
                {
                    nodeStack.push(root);
                    root = root->left;
                }
            }
        }
        
        return result;
    }
};
