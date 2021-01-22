/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL && q != NULL)//结构上不相同
	{
		return false;
	}
	if (p != NULL && q == NULL)//结构不相同
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	//让t对s的每一棵子树进行比较
	if (s == NULL)
	{
		return false;
	}
	//相等了
	if (isSameTree(s, t))
	{
		return true;
	}
	//实则在遍历这棵树，让每个结点都成为根，
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}