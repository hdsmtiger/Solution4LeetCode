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
    void calculateNext(TreeNode* node, int tempS, int sum, vector<int> onsS, vector<vector<int> >  &result)
    {
        onsS.push_back(node->val);
        if(node->left == NULL && node->right == NULL && tempS == sum)
        {
            result.push_back(onsS);
            return;
        }
            
        if(node->left != NULL)
            calculateNext(node->left, tempS+node->left->val, sum, onsS, result);
        
        if(node->right!=NULL)
            calculateNext(node->right, tempS+node->right->val, sum, onsS, result);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
            
        vector<vector<int> > result; 
        vector<int> oneSolution;
        
        if(root == NULL)
            return result;
        int tempS = 0;
        
        tempS = root->val;
        
        oneSolution.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && tempS == sum)
            result.push_back(oneSolution);
        
        
        if(root->left != NULL)
            calculateNext(root->left, tempS+root->left->val, sum, oneSolution, result);

        
        if(root->right!=NULL)
            calculateNext(root->right, tempS+root->right->val, sum, oneSolution, result);
        
        return result; 
    }
};
