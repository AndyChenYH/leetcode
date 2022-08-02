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
	TreeNode* root = new TreeNode(2, new TreeNode(2), new TreeNode(2));
	cout << root << endl;
	function<bool(TreeNode*, int, int)> valid = [&] (TreeNode* root, int lo, int hi) {
		db(root->val, lo, hi);
		if (!(lo <= root->val && root->val <= hi)) return false;
		bool yes = true;
		if (root->left != nullptr) {
			yes &= valid(root->left, lo, min(root->val, hi));
		}
		if (root->right != nullptr) {
			yes &= valid(root->right, max(root->val, lo), hi);
		}
		return yes;
	};
	bool res = valid(root, INT_MIN, INT_MAX);
	printf("%d\n", res);
}
