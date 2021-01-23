/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int dep, dep1, dep2;
	dep1 = TreeDepth(root->left);
	dep2 = TreeDepth(root->right);
	return dep1>dep2 ? dep1 + 1 : dep2 + 1;
}
bool isBalanced(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	if (abs(TreeDepth(root->left) - TreeDepth(root->right)) <= 1)
	{
		return isBalanced(root->left) && isBalanced(root->right);
	}
	return false;
}