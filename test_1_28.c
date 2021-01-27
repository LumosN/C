/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void _inorderTraversal(struct TreeNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;
	_inorderTraversal(root->left, array, pi);
	array[*pi] = root->val;
	(*pi)++;
	_inorderTraversal(root->right, array, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int i = 0;
	int* array = (int*)malloc(sizeof(int)*size);
	_inorderTraversal(root, array, &i);
	*returnSize = size;
	return array;
}