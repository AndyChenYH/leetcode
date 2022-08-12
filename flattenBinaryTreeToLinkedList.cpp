#include "../utils.cpp"
#include "TreeNode.cpp"
using namespace std;

int main() {
	/*
	TreeNode *root = 
		new TreeNode(1,
				new TreeNode(2,
					new TreeNode(3),
					new TreeNode(4)),
				new TreeNode(5,
					nullptr,
					new TreeNode(6)));
					*/
	TreeNode *root = new TreeNode(1, new TreeNode(2), nullptr);
	TreeNode *cur = root;
	while (cur->right != nullptr || cur->left != nullptr) {
		if (cur->left != nullptr) {
			TreeNode *c = cur->left;
			while (c->right != nullptr) c = c->right;
			c->right = cur->right;
			cur->right = cur->left;
			cur->left = nullptr;
		}
		else cur = cur->right;
	}
	cout << root;
}
