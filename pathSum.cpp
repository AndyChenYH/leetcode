#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

bool sol(TreeNode *root, int tar) {
	assert(root != nullptr);
	tar -= root->val;
	if (root->left == nullptr && root->right == nullptr) {
		return tar == 0;
	}
	bool res = false;
	if (root->left != nullptr) res |= sol(root->left, tar);
	if (root->right != nullptr) res |= sol(root->right, tar);
	return res;

}
int main() {
	TreeNode *root = 
		new TreeNode(5,
				new TreeNode(4,
					new TreeNode(11,
						new TreeNode(7),
						new TreeNode(2)),
					nullptr),
				new TreeNode(8,
					new TreeNode(13),
					new TreeNode(4,
						nullptr,
						new TreeNode(1))));
	cout << root;
	printf("%d\n", sol(root, sm));
}
