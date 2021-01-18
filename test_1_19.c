/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root){
	int dep, dep1, dep2;
	if (root == NULL)
	{
		return 0;
	}
	dep1 = maxDepth(root->left);
	dep2 = maxDepth(root->right);
	dep = dep1>dep2 ? dep1 + 1 : dep2 + 1;
	return dep;
}