/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        
        if(root->left != NULL)
        {
            if(root->right !=NULL)
                root->left->next = root->right;
            else if(root->next !=NULL)
            {
                TreeLinkNode *node = root->next;
                while(node != NULL && node->left == NULL && node->right == NULL)
                    node = node->next;
                if(node != NULL)
                if(node->left !=NULL)
                    root->left->next = node->left;
                else if(node->right != NULL)
                    root->left->next = node->right;
            }
        }
        
        if(root->right != NULL)
        {
            TreeLinkNode *node = root->next;
            while(node != NULL && node->left == NULL && node->right == NULL)
                node = node->next;
            if(node != NULL)
            if(node->left !=NULL)
                root->right->next = node->left;
            else if(node->right != NULL)
                root->right->next = node->right;
            
        }
        connect(root->right);  
        connect(root->left);
         
    }
};
