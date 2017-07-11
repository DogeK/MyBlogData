#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;
	stack<TreeNode*> s;
	TreeNode *p = pRootOfTree;
	TreeNode *pre;
	bool isFirst = true;
	while(p != NULL || !s.empty())
	{
		while(p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		p = s.top();
		cout << "p:" << p->val << endl;
		s.pop();
		if (isFirst)
		{
			pRootOfTree = p;
			pre = pRootOfTree;
			isFirst = false;
		}
		else
		{
			cout << "preBefore:" << pre->val;
			pre->right = p;
			p->left = pre;
			pre = p;
			cout << " preAfter:" << pre->val << endl;
		}
		p = p->right;
	}
	return pRootOfTree;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}