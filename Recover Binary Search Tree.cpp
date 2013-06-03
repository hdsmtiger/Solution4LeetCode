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

    void checkSubTree(TreeNode *root, int num1, int num2)
  {
		if(root == NULL)
            return;
		checkSubTree(root->left, num1, num2);
		if(root->val == num1)
			root->val = num2;
		else if(root->val == num2)
			root->val = num1;
		checkSubTree(root->right, num1, num2);
	}

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        vector<int> nodeList;
        
        scanSubTree(root->left,nodeList);
        nodeList.push_back(root->val);
        scanSubTree(root->right, nodeList);
        
		int num1=0, num2=0;
		bool firstFound = false, secondFound = false;

        int length = nodeList.size();
		if(length == 1)
			return;
        for(int i=1; i<length; i++)
		{
			if(firstFound == false)
                if(nodeList[i]<nodeList[i-1])
				{
					firstFound = true;
					num1 = nodeList[i-1];
					//num2 = nodeList[i];
				}

			if(nodeList[i] < nodeList[i-1])
				num2 = nodeList[i];
		}
        
		checkSubTree(root->left, num1, num2);
		if(root->val == num1)
			root->val = num2;
		else if(root->val == num2)
			root->val = num1;
		checkSubTree(root->right, num1, num2);

    }
};
