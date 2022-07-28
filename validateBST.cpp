#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;


int main() {
	/*
	TreeNode* root = new TreeNode(5,
			new TreeNode(1),
			new TreeNode(4,
				new TreeNode(3),
				new TreeNode(6)));
	*/
	TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	function<bool(TreeNode*, int, int)> valid = [&] (TreeNode* root, int lo, int hi) {
		if (!(lo <= root->val && root->val <= hi)) return false;
		bool yes = true;
		if (root->left != nullptr) {
			yes &= valid(root->left, max(root->left->val, lo), root->val);
		}
		if (root->right != nullptr) {
			yes &= valid(root->right, root->val, min(root->right->val, hi));
		}
	};
	bool res = valid(root, INT_MIN, INT_MAX);
	printf("%d\n", res);
}
