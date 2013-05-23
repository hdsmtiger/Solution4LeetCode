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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
        return 0;
        
        int result = 0;
        
        int leftDepth = 1 + maxDepth(root->left);
        int rightDepth = 1 + maxDepth(root->right);
        
        if(leftDepth > rightDepth)
            return leftDepth;
        return rightDepth;
    
    }
};
