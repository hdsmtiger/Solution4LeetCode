#include <iostream>
using namespace std;

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:

  TreeNode* processRightNode(TreeNode *root)
	{
		if(root == NULL)
			return NULL;

		if(root->left == NULL && root->right == NULL)
			return root;

		if(root->left != NULL)
		{
			TreeNode* tempNode = root->left;
			root->left = root->right;
			root->right = tempNode;
			
			TreeNode* lastNodeInRight = root;
			if(root->right != NULL)
			    lastNodeInRight = processRightNode(root->right);

			lastNodeInRight->right = root->left;
			root->left = NULL;

			return processRightNode(lastNodeInRight);

		}else
			return processRightNode(root->right);

	}

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		TreeNode* lastNode = root;
		if(lastNode != NULL)
		{
			if(lastNode->left != NULL)
			{//exchange left and right
				TreeNode* tempNode = lastNode->left;
				lastNode->left = lastNode->right;
				lastNode->right = tempNode;
				
				TreeNode* lastNodeInRight = lastNode;
				if(lastNode->right != NULL)
					lastNodeInRight = processRightNode(lastNode->right);

				lastNodeInRight->right = lastNode->left;
				lastNode->left = NULL;

				processRightNode(lastNodeInRight);

			}else
			{
				processRightNode(root->right);

			}
		}
        
    }
};

//
//void main()
//{
//	TreeNode node1 = TreeNode(1), node2 = TreeNode(2),node3 = TreeNode(3),node4 = TreeNode(4),node5 = TreeNode(5),node6 = TreeNode(6);
//
//	node1.left = &node2;
//	node2.left = &node3;
//	node2.right = &node4;
//	node1.right = &node5;
//	node5.right = &node6;
//
//	Solution s;
//	s.flatten(&node1);
//
//	getchar();
//
//}
