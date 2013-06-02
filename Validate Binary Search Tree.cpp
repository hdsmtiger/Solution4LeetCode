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

    void scanSubTree(TreeNode *root, vector<int> &nodeList)
    {
        if(root == NULL)
            return;
        scanSubTree(root->left,nodeList);
        nodeList.push_back(root->val);
        scanSubTree(root->right, nodeList);
        
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        vector<int> nodeList;
        
        scanSubTree(root->left,nodeList);
        nodeList.push_back(root->val);
        scanSubTree(root->right, nodeList);
        
        int length = nodeList.size();
        for(int i=1; i<length; i++)
            if(nodeList[i]<=nodeList[i-1])
                return false;
        return true;
    }
};
