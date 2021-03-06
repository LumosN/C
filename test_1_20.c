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
//求树的结点个数，才能来创建合适的数组
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void _preorderTraversal(struct TreeNode* root, int* array, int* i)
{
	if (root == NULL)
	{
		return;
	}
	array[(*i)++] = root->val;
	_preorderTraversal(root->left, array, i);
	_preorderTraversal(root->right, array, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* array = (int*)malloc(sizeof(int)*size);
	int i = 0;
	_preorderTraversal(root, array, &i);
	*returnSize = size;
	return array;
}