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
/*
    int searchPosition(vector<int> num, int startIndex, int target)
    {
        int size = num.size();
        for(int i=startIndex; i<size; i++)
            if(num[i] == target)
                return i;
        return -1;
        
    }
    */    
    TreeNode *buildSubTree(vector<int> preorder, vector<int> inorder, int &count,
                           int begin, int end)
   {
       if(begin>end)
           return NULL;
    
        TreeNode *head = new TreeNode(preorder[count]);
        
        //int leftP = searchPosition(inorder, begin, preorder[count]);
        
        int leftP = 0;
        
        int size = inorder.size();
        for(leftP = begin; leftP<size; leftP++)
        {
            if(inorder[leftP] == preorder[count])
                break;
        }
        
        count++;
        if(begin <= leftP - 1)
            head->left = buildSubTree(preorder, inorder, count, begin, leftP - 1);
        if(leftP + 1<=end)
        head->right = buildSubTree(preorder, inorder, count, leftP+1, end);
        
        return head;
       
   }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = preorder.size();
        if(size == 0)
            return NULL;
        
        TreeNode *head = new TreeNode(preorder[0]);
        
        int count = 1;
        
        int leftP = searchPosition(inorder, 0, preorder[0]);
        head->left = buildSubTree(preorder, inorder, count, 0, leftP - 1); 
        head->right = buildSubTree(preorder, inorder, count, leftP+1, size - 1);
        return head;
    }
};
