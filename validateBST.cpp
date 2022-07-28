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
		db(lo, hi);
		if (root == nullptr) return true;
		if (!(lo <= root->val && root->val <= hi)) return false;
		lo = max(root->val, lo);
		hi = min(root->val, hi);
		return valid(root->left, lo, root->val) && valid(root->right, root->val, hi);
	};
	bool res = valid(root, INT_MIN, INT_MAX);
	printf("%d\n", res);
}
