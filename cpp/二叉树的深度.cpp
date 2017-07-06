#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot) return 0;
	return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
}

int main(int argc, char const *argv[])
{
	
	return 0;
}