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

    int maxSubPathSum(TreeNode *root, long long &result)
    {
        if(root == NULL)
            return INT_MIN / 4;
        int leftSum = maxSubPathSum(root->left, result);
        int rightSum = maxSubPathSum(root->right, result);
        
        if(leftSum > result)
            result = leftSum;
        
        if(rightSum > result)
            result = rightSum;
            
        if(root->val > result)
            result = root->val;
        
        if(root->val + leftSum > result)
            result = root->val + leftSum;
        
        if(root->val + rightSum > result)
            result = root->val + rightSum;
        
        if(root->val + leftSum + rightSum > result)
            result = root->val + leftSum + rightSum;
        
        if(leftSum <= 0 && rightSum <= 0)
            return root->val;
        if(leftSum > rightSum)
            return leftSum + root->val;
        return rightSum + root->val;
        
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        
        long long result = INT_MIN;
        int leftSum = maxSubPathSum(root->left, result);
        int rightSum = maxSubPathSum(root->right, result);
        if(leftSum > result)
            result = leftSum;
        
        if(rightSum > result)
            result = rightSum;
            
        if(root->val > result)
            result = root->val;
        
        if(root->val + leftSum > result)
            result = root->val + leftSum;
        
        if(root->val + rightSum > result)
            result = root->val + rightSum;
        
        if(root->val + leftSum + rightSum > result)
            result = root->val + leftSum + rightSum;
        return result;
    }
};
