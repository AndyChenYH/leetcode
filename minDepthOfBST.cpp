#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

int minDepth(TreeNode* root) {
	if (root->left == nullptr && root->right == nullptr) return 1;
	int res = 2000;
	if (root->left != nullptr) {
		res = minDepth(root->left);
	}
	if (root->right != nullptr) {
		res = min(res, minDepth(root->right));
	}
	return res + 1;
}
int main() {
	TreeNode *root = 
		new TreeNode(1,
				nullptr,
				new TreeNode(2,
					nullptr,
					new TreeNode(3)));
	printf("%d\n", minDepth(root));
}
