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


    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return true;
            
        int leftDepth =  maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        bool result = true;
        if(leftDepth - rightDepth > 1 || rightDepth - leftDepth > 1)
            return false;
        
        result = result && isBalanced(root->left);
        
        if(result == false)
            return result;
        
        result = result && isBalanced(root->right);
        
        return result;
        
    }
};
