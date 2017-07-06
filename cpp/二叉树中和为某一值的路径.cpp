#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
{
	stack<int> treeStack;
	treeStack.push(root);
	while (treeStack.empty())
	{
		TreeNode *leaf = 
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}