/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isUnivalTree(struct TreeNode* root){
	//1.左右结点都没有
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	//2.只有左结点
	else if (root->right == NULL)
	{
		if (root->val == root->left->val)
		{
			return isUnivalTree(root->left);
		}
		else return false;
	}
	//3.只有右结点
	else if (root->left == NULL)
	{
		if (root->val == root->right->val)
		{
			return isUnivalTree(root->right);
		}
		else return false;
	}
	//4.左右结点都存在
	else
	{
		if (root->val == root->left->val && root->val == root->right->val)
		{
			return isUnivalTree(root->left) && isUnivalTree(root->right);
		}
		else return false;
	}
}