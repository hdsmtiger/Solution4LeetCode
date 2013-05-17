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

    void calculateNext(TreeNode* node, int tempS, int sum, bool &result)
    {
        if(node->left == NULL && node->right == NULL && tempS == sum)
        {
            result = true;
            return;
        }
            
        if(node->left != NULL)        
            calculateNext(node->left, tempS+node->left->val, sum, result);
        
        if(result == false && node->right!=NULL)
            calculateNext(node->right, tempS+node->right->val, sum, result); 
    }

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool result = false;
        
        if(root == NULL)
            return false;
        
        int tempS = 0;
        
        tempS = root->val;
        
        if(root->left == NULL && root->right == NULL && tempS == sum)
            result = true;
        
        if(!result && root->left != NULL)        
            calculateNext(root->left, tempS+root->left->val, sum, result);
        
        if(result == false && root->right!=NULL)
            calculateNext(root->right, tempS+root->right->val, sum, result);        
        
        return result;        
    }
};
