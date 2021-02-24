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
void travel(struct TreeNode* root, int depth, int* returnSize, int* res){
	if (root == NULL) return;

	if (depth > *returnSize){
		res[*returnSize] = root->val;
		*returnSize = depth;
	}
	// ���� �ҡ�������
	travel(root->right, depth + 1, returnSize, res);
	travel(root->left, depth + 1, returnSize, res);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
	// ��ʼ���������СΪ0
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int)* 1000);
	// ��ʼ���Ϊ1
	travel(root, 1, returnSize, res);
	return res;
}